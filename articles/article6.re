= static なメソッドを作りたくなった際に、拡張関数の方がわかりやすくないか考えるようになった

//list[use-extention-function][staticなメソッドによるチェックと拡張関数によるチェック]{
// staticなメソッドによるチェック
fun isCat(animalSpecies: String) = animalSpecies.lowercase() == "cat"

val animalSpecies1 = "Cat"
println(isCat(animalSpecies1)) // true

val animalSpecies2 = "Dog"
println(isCat(animalSpecies2)) // false


// 拡張関数によるチェック
fun String.isCat() = this.lowercase() == "cat"

val animalSpecies1 = "Cat"
println(animalSpecies1.isCat()) // true

val animalSpecies2 = "Dog"
println(animalSpecies2.isCat()) // false
//}

この例が良いかどうかは疑問が残るところですが、拡張関数を利用したほうが自然に読み下せるように書けることが多そう、という雰囲気は伝わるのではないかと思います。

また、拡張関数は @<strong>{Int や float といったプリミティブ型}に対しても利用できたり、@<strong>{private} や @<strong>{関数内関数}としても利用できるので例えば下記のような使い方もできます。

//list[apply-extention-function-to-premitive][プリミティブ型への拡張関数適用例]{
// android で、drawable resource id から drawable を取得するための関数
// 全体への影響が大きすぎて、public では宣言しづらいので private で宣言
private fun Int.toDrawable(context: Context) =
    ContextCompat.getDrawable(context, this)

// 拡張関数を使わない場合はこんな感じ
ContextCompat.getDrawable(context, R.drawable.icon_cat)

// 拡張関数を使う場合はこんな感じ
R.drawable.icon_cat.toDrawable(context)
//}

Android では、Apiレベルによる違いを利用するために、@<strong>{xxxCompat} というクラスを利用することが多いのですが、Compatクラスの静的な呼び出しになるのでどうしてもコードが長くなりがちです。

リソースを取得するコードはよく利用するので全体に適用したところなのですが、リソースを指定するキーは単なる Int 型なので全体に適用するには範囲が広すぎます。

そういった時に、必要な個所でだけ private で拡張関数を定義してやることで、コードが短くかつ分かりやすくかけるようになります。