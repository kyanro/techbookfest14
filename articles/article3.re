= 画面を作ろう！(Html)
仕様を満たせる、htmlの画面を作ります。

仕様は、

@<strong>{二つの単語を入力すると、合成した単語と、その来歴をでっちあげるサービス} なので、

 * 二つの入力欄がある
 ** それぞれの入力欄には、元になる単語が入る
 * 二つの入力欄の下には、合成した単語が表示される
 * 合成した単語の下には、その来歴が表示される
 * 二つの単語を合成するボタンがある

という要件を満たすhtmlの画面が作れればよさそうです。

今回は ChatGPTさんに作成をお願いしてみましょう。

//list[html-chat-gpt][ChatGPT4さんにお願いした文言]{
"二つの単語を入力すると、合成した単語と、その来歴をでっちあげるサービス" を作成したいと思っています。
下記の仕様を満たすhtmlの画面を作成してください。

装飾にはTailwind CSSを利用してください。
JavaScriptフレームワークは、最新のAlpine.jsを利用してください。
楽しさが伝わるような装飾だと嬉しいです。


```仕様
 * 二つの入力欄がある
 ** それぞれの入力欄には、元になる単語が入る
 * 二つの入力欄の下には、合成した単語が表示される
 * 合成した単語の下には、その来歴が表示される
 * 二つの単語を合成するボタンがある
//}

//list[html-chat-gpt-code][実際に提案されたコード。(デザイン以外の長い部分は手動で省略)]{
<!DOCTYPE html>
<html>
  <head>
    <title>Word Fusion Fun</title>
    <!-- Include Tailwind CSS via CDN -->
    <link
      href="省略"
      rel="stylesheet"
    />
    <!-- Include Alpine.js via CDN -->
    <script
      src="省略"
      defer
    ></script>
  </head>
  <body class="bg-blue-100 flex items-center justify-center h-screen">
    <div
      class="bg-white p-10 rounded shadow-md w-64"
      x-data="{ word1: '', word2: '', fusion: '', history: '' }"
    >
      <h1 class="text-2xl mb-4">Word Fusion Fun!</h1>
      <input
        type="text"
        x-model="word1"
        class="border p-2 rounded mb-2 w-full"
        placeholder="First word"
      />
      <input
        type="text"
        x-model="word2"
        class="border p-2 rounded mb-2 w-full"
        placeholder="Second word"
      />
      <button
        @click="省略"
        class="bg-blue-500 text-white p-2 rounded w-full"
      >
        Create Fusion
      </button>
      <h2 class="text-xl my-4" x-text="fusion"></h2>
      <p x-text="history"></p>
    </div>
  </body>
</html>

//}


//image[html_chat_gpt_1][ChatGPTさんによって作成されたhtml画面][scale=0.5]{
//}

すばらしいですね！

特に手直しする必要もなく、仕様を満たす画面が作成されました。
