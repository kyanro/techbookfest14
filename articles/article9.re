== DataStoreをアプリに組み込むにゃ！ ~ 誰も僕を止めることはできない1 ~

無事、開くURL選択機能を追加した僕は、引き続きこのアプリを使い続けました。

(以下茶番略)

使い続けていても特に不満はなかったのですが、新しい androidx のライブラリがリリースされてしまいました。

SharedPreferences の置き換えることができる DataStore です。なんとデータの変更をFlowで通知できる優れモノです。

これは使ってみるしかありません。
//blankline
今のままでも十分ですし、特に変えたからと言ってユーザに利益があるわけではありません。
ですが、心の中の猫PMが、横たわっている僕に語り掛けてきます。
//blankline
猫PM「DataStoreをアプリに組み込むにゃ！」
//blankline
犬PM「いや、しかしそんなことをしてもユーザのためにはならな（」
//blankline
猫PM「うるさいにゃ！」

===[column] 仕様変更の原因
猫PMの好奇心による独断専行
//blankline
対応方針

 * DataStoreをアプリに組み込む
 * UIの最後の状態を保存するのにつかえばいいかな……？

作業日数 + 2

参考: DataStoreの公式サイト

@<href>{https://developer.android.com/topic/libraries/architecture/datastore}

===[/column]