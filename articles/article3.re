= scopeを絞った拡張関数の利用
#@# interface で宣言。companion object に設定して with で利用

Android のアプリを書いていると、メソッドの引数としてリソースID(Int型)を渡してなんらかのインスタンスを得る、という処理をかくことがままあります。

kotlinを使って書いていると、そういうときに拡張関数を使ってリソースIDをインスタンスに変換してやると便利なのではないか、と思いがちです。
//blankline
もちろん拡張関数を素直にかいてもよいのですが、そうすると、

 * リソースIDではない Int 型に対しても拡張関数の処理が実行できてしまう

という問題が発生してしまいます。

//list[int-extensions][Int型の拡張関数を作成した際に問題になる例]{
// R.drawable.my_icon のようなリソースを Drawable に変換する拡張関数
fun Int.toDrawable(context: Context) =
    ContextCompat.getDrawable(context, this)

// 正しく使われる例
R.drawable.my_icon.toDrawable(context)

// 誤って使われる例
(1 + 2).toDrawable(context)
//}

このようなときは拡張関数をあるスコープの中でのみ利用できるように制限しておくと便利です
//list[int-extensions-in-resource-scope][Int型の拡張関数を特定のスコープ限定にする例]{
interface DrawableScope {
    // R.drawable.my_icon のようなリソースを Drawable に変換する拡張関数
    fun Int.toDrawable(context: Context) =
        ContextCompat.getDrawable(context, this)
}

// 正しく使われる例
with(object: DrawableScope{}) {
    R.drawable.my_icon.toDrawable(context)
}

// 誤って使えない例
(1 + 2).toDrawable(context)

//}

Int 型のように、広く使われている型に対する拡張関数の利用を制限することができました！
//blankline
もちろん Int 型以外にも利用できますので似たような問題が発生したときにはぜひ上記を思い出してみてください。
//blankline
余談ですが、頻繁に利用する場合は companion object を定義しておくと、少し便利になります。

//list[int-extensions-in-resource-scope2][少し便利な定義方法と使い方]{
interface DrawableScope {
    companion object: DrawableScope
    // 以下scopeを絞りたい拡張関数等...
}

// companion object が定義されているため、Interface名のみで利用可能
with(DrawableScope) {
    R.drawable.my_icon.toDrawable(context)
}
//}
