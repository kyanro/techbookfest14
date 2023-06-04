= APIを作ろう！
無事に素晴らしい画面ができたので、次はAPIを作ります。

本来であれば、画面から入力された二つの単語データを元に、何かしらの処理を行い、単語を元に作成されたアイテム、およびその来歴を返すAPIを作るのですが、今回はAPIを叩いたら固定の結果が返ってくるだけのモックを作成することにします。

== APIの仕様
 * Cloudflare Workersを使ってAPIを作成します。
 ** エンドポイントの作成にはHonoを使います。
 * エンドポイントは`/api/fusion_relic?word1=:word1&word2=:word2`とします。
 ** `:word1`と`:word2`にはそれぞれ単語が入ります。
 ** このエンドポイントにGETリクエストを送ると、以下のようなJSONが返ってきます。
 *** `{"合成されたアイテム": { "名称" : "合成されたアイテム" , "来歴": "来歴テキスト"}}`

今回もまずはChatGPTさんにお願いしてみましょう。

//list[api-chat-gpt-request-1][ChatGPT4さんにお願いした文言1]{
フロントエンドのJavaScriptから呼び出されるAPIを作りたいと思っています。

仕様は下記の通りです。コードを作成してください

```仕様
 * Cloudflare Workersを使ってAPIを作成します。
 ** エンドポイントの作成にはHonoを使います。
 * エンドポイントは`/api/fusion_relic?word1=:word1&word2=:word2`とします。
 ** `:word1`と`:word2`にはそれぞれ単語が入ります。
 ** このエンドポイントにGETリクエストを送ると、以下のようなJSONが返ってきます。
 *** `{"合成されたアイテム": { "名称" : "合成されたアイテム" , "来歴": "来歴テキスト"}}`
//}

このお願いをした所、次のような返答でした。

//list[api-chat-gpt-response-1][ChatGPT4さんにお願いした結果1]{
Cloudflare Workersを使って、指定された仕様のAPIを作成する場合、以下のようなコードを使用することができます。ただし、Honoがどのようにエンドポイントの作成に使われるかについては具体的な情報がないため、ここではCloudflare Workersの基本的な構成でAPIを作成します。
// コードは省略
//}

おそらく、動くであろうコードがは提示されましたが、どうやらHonoについては知らないようです。

ですが、今回はHonoでシンプルに作成したいため、@<strong>{最近追加されたBrowse機能(URLを与えるとその情報も加味して返答してくれる)}を使ってみることにしました。
//blankline
幸いHonoにはcloudflare-workersを利用したGetting Startedがあるので、そのURLを与えて続けてお願いしてみます。

//list[api-chat-gpt-request-2][ChatGPT4さんにお願いした文言2]{
cloudflare workers での honoの利用方法は下記の通りです。
参考にできますか？

https://hono.dev/getting-started/cloudflare-workers
//}

//list[api-chat-gpt-response-2][ChatGPT4さんにお願いした結果2]{
ご提示いただいたリンクを元に、Cloudflare Workersを使ってHonoでAPIを作成する基本的なコードを以下に示します。エンドポイント/api/fusion_relic?word1=:word1&word2=:word2を作成し、GETリクエストを送ると指定した形式のJSONを返すようにしています。
// 以下セットアップ方法や説明等。省略
//}

//list[api-chat-gpt-code][実際に提案されたコード]{
import { Hono } from 'hono'

const app = new Hono()

app.get('/api/fusion_relic', (c) => {
    const word1 = c.req.query('word1')
    const word2 = c.req.query('word2')

    const fusionItem = `${word1}と${word2}の融合アイテム`

    const result = {
        "合成されたアイテム": {
            "名称": fusionItem,
            "来歴": `${word1}と${word2}を融合して作られました`
        }
    }

    return c.json(result)
})

export default app
//}

素晴らしいですね！

これをこのまま貼り付け、Cloudflare Workersにdeployしてみたところ、そのまま動きました。

AIさんに理解しやすいドキュメントが整備されていると、素早い開発ができそうでとても良いですね。