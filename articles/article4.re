= 最大値最小値の設定が必要な際に標準拡張関数(coerceXXX)を使うようになった
coerceXXX は呼び出した値を範囲内(or 以上 or 以下)に収めるkotlinの標準拡張関数です。

たとえば、引数として渡されたindexをもとにリストの要素を取得する関数があったとします。

indexが範囲外の場合、例外が発生してしまうため、大抵は範囲が正しいかのチェックを行ってから実際に要素を取得するかと思います。
//blankline
//list[check-range][範囲チェック後に要素を取得する例]{
fun getItem(index: Int): Int {
    val targetList = listOf(1,2,3)

    // index の範囲が適切であれば、与えられたindexの要素を返す
    // index が0未満の場合は最初の要素を返す
    // index がリストのサイズを超える場合は最後の要素を返す    
    val safeIndex = when {
        index >= 0 && index < targetList.size -> index
        index < 0 -> 0
        else -> targetList.size - 1
    }
    return targetList[safeIndex]
}
//}

もちろんこのように書いてもよいのですが、coerceIn関数を利用することにより簡潔に書くことができます。
//list[check-range2][coerceInを利用して要素を取得する例]{
fun getItem(index: Int): Int {
    val targetList = listOf(1,2,3)

    val safeIndex = index.coerceIn(
        minimumValue = 0,
        maximumValue = targetList.lastIndex,
    )
    return targetList[safeIndex]
}
//}

最小値、最大値を引数で明示できるようになり、とても分かりやすくなりました。
//blankline
似たようなパターンは色々な場面で出てくるかと思いますので、よさそうと思った方はぜひつかってみてください。
//blankline
範囲の指定以外では、最小値のみ、最大値のみを指定できる関数も利用できます。

最小値のみ: coerceAtLeast

最大値のみ: coerceAtMost