= コンパイラによるチェックが効かせられる書き方にできないか考えるようになった。

@<strong>{val} をローカル変数で利用する場合、

 * 一度だけ代入できる
 * 代入されていない状態で利用しようとするパターンがあるとコンパイルエラーになる

これを利用して、何らかの処理に漏れがあった場合に、人力ではなくコンパイラによるチェックで見つけることができないか考えることが多くなった。

//list[use-val][valを利用したコンパイルチェックが効く書き方の例]{
fun embraceCat(isHappy: Boolean, cat: Cat) {
    val embraceDurationSec: Int
    val embraceStrength: String

    if (isHappy) {
        embraceDurationSec = 10
        embraceStrength = "普通"
    } else {
        embraceDurationSec = 60
        embraceStrength = "強め"
    }

    // embraceDurationSec, embraceStrength のどちらも必ず明示的に値の設定が行われていることが保証されている
    cat.embrace(embraceDurationSec, embraceStrength)
}
//}
