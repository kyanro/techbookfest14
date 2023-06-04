= (架空の)Webサービスの仕様を考える

プログラマにとってコードのサンプルといえば、こんにちは世界。

サービスのサンプルといえば、TODOアプリというのが定番です。

親の顔よりも見た回数が多いという人も多いのではないでしょうか。

== AIさんの力を知るにはどんなサービスがよいか？
しかし、今回はせっかく新しいことにチャレンジしてみるのです。サービスも新しいものを作って行きたいと思います。

また、AIさんの力を借りることでどのくらい楽になるかも知れるとよいと思います。

さらにそれが実際に動いたら最高ですね！

ということで、今回は「二つの単語を入力すると、合成した単語と、その来歴をでっちあげるサービス」を作ってみることにします。

== 今回作るWebサービスの仕様
 * 二つの単語を入力すると、合成した単語と、その来歴をでっちあげるサービス

=== 選定理由
 * 新規性がある
 * AIさんと作らない場合にどのくらいの手間がかかるかが分かる
 * 実際に動くと面白そう
 ** 本書では、フロントエンド、バックエンドの開発までを行う予定で、実際にデプロイまでは行いません
 *** ただし、フロントエンドからバックエンドのこのAPIをたたくようにして、デプロイする、という作業を行えば実際にサービスとして動く、という状態を目指します。

