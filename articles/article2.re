= 非同期処理をコルーチンで書くようになった

== コルーチンを積極的に使うようになったパターンの例

 * Api の実行
 ** 1回だけ実行する
 *** 1回目の結果を利用して2回目をたたく
 ** 複数のリクエストを並列で実行する
 * androidの AsyncTask(古い非同期処理パターン)の置き換え

Apiの実行についてはよく見るかと思うので、ここではandroidの AsyncTask(古い非同期処理パターン)の置き換えの例を示します。

//list[null-1][今までの作り]{
// AsyncTaskクラスの作成
val task = object : AsyncTask<Void?, Void?, Int>() {
    override fun doInBackground(vararg p0: Void?): Int {
        // 時間がかかる処理
        return superLongTask()
    }

    override fun onPostExecute(result: Int) {
        // 結果を表示
        textView.text = result.toString()
    }
}

// 処理の開始
task.execute()
//}

古い非同期処理パターンでは、実際の処理の流れとコードの流れが一致していなかったり、非同期処理専用のクラスの使い方を覚える必要がある等の問題がありました。
//blankline
これをコルーチンで書き直してみます。
//list[null-2][コルーチンでの作り]{
val scope = CoroutineScope(Dispatchers.IO)
scope.async {
    // 時間がかかる処理
    val result = superLongTask()
    withContext(Dispatchers.Main) {
        // 結果を表示
        textView.text = result.toString()
    }
}
//}

コルーチンを利用したパターンでは、

 * 実際の処理の流れとコードの流れが一致
 * ほとんど同期的なコードと書き方が変わらない

ようにかくことが出来ました。
//blankline
今回は実際に局所的な書き換えの為に多少分かりにくい部分があったり、気を付けなければいけない部分が残っていたりしますが、もう少し大きめのリファクタリングが可能であれば、suspend function を利用するなどしてもっと直感的に書くことも可能です。

詳しくはぜひ公式のコルーチンのドキュメントをご参照ください。
