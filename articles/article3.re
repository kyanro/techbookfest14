= 早期リターンをよく使うようになった

Kotlin では、型チェックを行った後に、自動的にチェック対象をその型として扱うことができる機能がある(スマートキャスト)

早期リターンを利用することで、Nullable な型を NotNull な型にスマートキャストできて便利なのでよく使うようになった。

//list[early-return1][早期リターンを利用して NotNull な型として扱う例]{
fun checkCatOrDog(animalType: String?): Boolean {
    animalType ?: return false
    // ここから animalType を NotNull として扱えるので、NPE を気にすることなく、 String のメソッドを利用できる
    return when (animalType.lowercase()) {
        "cat", "dog" -> true
        else -> false
    }
}
//}
