= Null を積極的に使うようになった

== 何もないことを表現するのに null を使うようになった
例えば、何かItemを選択した状態を表現する場合、選択していない場合は素直にnullをつかうようになった。

//list[null-1][今までの作り]{
// NPEが発生しないようにする
val EMPTY_ITEM = Item("empty_item")
val selectedItem: Item = EMPTY_ITEM
// 選択されたアイテム名を表示。
selectedItem.name
//}

今までは、 NullPointerException を警戒したり、NullCheckで煩雑にならないように、 EMPTY_ITEM などを定義してできるだけ null が入らないようにしていた。

//list[null-2][現在の作り]{
val selectedItem: Item? = null

// 選択されたアイテム名を表示。アイテム名が null なら代わりに任意の文字列を表示
val selectedItemName = selectedItem?.name ?: "no item selected"
//}

Kotlin では safe call でNPEが発生しないようにかけたり、Null チェックが楽にかけたりするので、素直に null を利用するようになった。

結果として、コード上の表現が、実際にやりたいことに近くなった。

== 例外を返す代わりに null を返せないか考えるようになった
Kotlinの標準Apiには xxxOrNull() のようなメソッドが多くあり、実際に使ってみると使い勝手が非常に良かった。

なので、自分でApiを設計する際にも OrNull を用意することが多くなった。

//list[null-3][OrNull のサンプル(数値のパース)]{
    val numStr = "1234"
    "1234".toIntOrNull() ?: 0 // 1234
    val str = "hoge"
    "hoge".toIntOrNull() ?: 0 // 0
//}




