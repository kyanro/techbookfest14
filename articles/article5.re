= typealias を使うようになった

最近、android 界隈では jetpack compose を利用して UI を構築することが増えてきました。

その際、実装効率をあげたり、確認のために実際のデータを @Composable な関数にわたしてプレビューを表示することがよくあります。

このときに、実際のデータの代わりとなる Fake なデータを渡すことも多いのですが、データ作成時に何度も出てくる長いクラス名があったりすると、

 * 似たような長い名前のクラスと混同してしまう
 * 実際には値の方が重要なのにクラス名に目が行ってしまう
 
 といったことが発生し、潜在的にバグの発生率があがってしまっているのではないか？と思うことが多々あります。
//blankline
このようなときは typealias が便利です。
(特に下記の様に、長い名前をキー、バリューにとるマップのようなクラスを利用する時)
//list[use-typealias1][typealiasを利用しない例]{
val map = mapOf(
    SuperLongLongLongLongNameClass()
            to SuperLongLongLongLongNameClass2()
)
//}

とても長くて、なんらかの見落としが発生してしまいそうです。
//blankline
これを typealias を利用して書き直してみます。
//list[use-typealias2][typealiasを利用して簡潔に書く例]{
// key, value, map に typealias を設定
typealias MapKey = SuperLongLongLongLongNameClass
typealias MapValue = SuperLongLongLongLongNameClass2
typealias MapAlias = Map<MapKey, MapValue>

// typealias で設定した map クラスを利用
val mapAlias: MapAlias = mapOf(MapKey() to MapValue() )
//}

とても短くなりましたね！
//blankline
typealias の利用には注意が必要な点も多いのですが、

 * テストコードなどで共通化を行わずに、素直にコードを書いた方がわかりやすい

 のようなときに、使うととても便利なので、興味を持った方は是非一度ためしてみてください。