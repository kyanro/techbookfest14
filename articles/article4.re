= valにできないか考えることが多くなった
Kotlin では変数宣言の際に @<strong>{var} と @<strong>{val} が利用できる。

@<strong>{val} で宣言すると、最初に代入された値は以後変更されないことが保証されるので、プログラムを読むときに理解しやすくなることが多い。
//blankline
Kotlin では、 @<strong>{if} や @<strong>{when} を式として扱うことができるので、これらを利用して @<strong>{val} で宣言できないか考えることが多くなった。

//list[use-val][valで宣言する例]{
val isHappy = when {
    cat.sleeping -> true
    dog.sleeping -> true
    else -> false
}
//}
