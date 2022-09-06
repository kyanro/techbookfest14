= コンストラクタに、依存するクラスを渡すことが多くなった

突然ですが、みなさんテスト書いてますか？僕は書いていません。

でも、テストが書きたくなった時にはすぐに書ける状態にしておきたいですよね？

テストを書きやすくするためには、依存するクラスを渡してやるのが一番簡単です。

ですが、毎回すべての依存するクラスを渡すというのは大変です。

そんなときに便利なのがデフォルト引数です。

これをうまく利用すると、通常の利用時は依存するクラスを意識しなくてもよくなる上、テストを書きやすい状態にすることができます。

例をみてみましょう。

現在時刻に応じて、「おはよう」「こんにちは」「おやすみ」を返すメソッドがあったとします。

//list[use-default-parameter][デフォルトパラメータを利用してテストしやすいメソッドにする]{
val MORNING_START_TIME: LocalTime = LocalTime.parse("05:00")
val NOON_START_TIME: LocalTime = LocalTime.parse("12:00")
val EVENING_START_TIME: LocalTime = LocalTime.parse("17:00")

// デフォルトパラメータを設定したメソッド
fun catGreeting(now: LocalTime = LocalTime.now()): String {
    return when {
        now.isAfter(MORNING_START_TIME) && now.isBefore(NOON_START_TIME) ->
            "おはようございますにゃ"
        now.isAfter(NOON_START_TIME) && now.isBefore(EVENING_START_TIME) ->
            "こんにちはにゃ"
        now.isAfter(EVENING_START_TIME) && now.isBefore(LocalTime.MIDNIGHT)->
            "こんばんはにゃ"
        now.isAfter(LocalTime.MIDNIGHT) && now.isBefore(MORNING_START_TIME) ->
            "こんばんはにゃ"
        else ->
            "こんばんにゃ"
    }
}

catGreeting() // 現在時刻に応じた挨拶がかえってくる。 例: おはようございますにゃ

catGreeting(LocalTime.parse("05:01")) // おはようございますにゃ
catGreeting(LocalTime.parse("12:01")) // こんにちはにゃ
catGreeting(LocalTime.parse("17:01")) // こんばんにゃ
//}

この例が良いかどうかは疑問が残るところですが、デフォルトパラメータを設定したことで、

 * 通常の利用時は LocalTime.now() に応じた挨拶
 * 指定の LocalTime の挨拶を取得したいときは、引数の LocalTime に応じた挨拶

を返せるようになりました。

これにより、現在はテストが書けていなかったとしても、将来テストが書きたいとなったときにはすぐに書ける状態を保つことができるようになります。

@<strong>{書けないから書かない} ではなく、 @<strong>{書けるのけれど書いていない} の間には大きな違いがあるのでうまく付き合っていきたいですね。