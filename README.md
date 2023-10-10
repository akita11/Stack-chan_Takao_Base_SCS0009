# Stack-chan_Takao_Base_SCS0009

現時点で ｽﾀｯｸﾁｬﾝ を組み立てる最もシンプルな方法と思われる、[タカオさん](https://twitter.com/mongonta555)の[タカオ版](https://mongonta.booth.pm/)で[Feetech社のシリアルサーボSCS0009](https://www.switch-science.com/products/8042)を使うためのボードです。（※現行のタカオ版筐体はSCS0009は使用できませんが、近日中にSCS0009版が公開予定とのことです）。M5Stack本体と2個のシリアルサーボモータSCS0009用コネクタ、給電用のUSB TypeCコネクタがついたボードです。電源スイッチもついています。まるごと一式、タカオ版のサーボ固定部分(Bracket)に収納できます。市販のUSB Type-CコネクタつきのACアダプタ等をつないで給電して使用します。以下のように、本体の後ろ側からUSB Type-Cケーブルで給電して動作させることができます。


## 表面実装部品版

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/ScTB0009-1.jpg" width="240px">

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/ScTB0009-2.jpg" width="240px">

※完成品としてスイッチサイエンスで委託販売予定です



## 挿入実装部品版

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/ScTB0009kit-1.jpg" width="240px">

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/ScTB0009kit-2.jpg" width="240px">


※部品キットとしてスイッチサイエンスで委託販売予定です

※部品キット版では、[組み立て手順](https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/Build/README.md)に沿って部品をはんだ付けしてください。／参考：[タカオ版Stack-chan_TakaoBaseの作り方](https://raspberrypi.mongonta.com/how-to-build-easy-stackchan-m5gobottom/)


## 他に用意するもの

- M5Stack本体 (Core BasicまたはCore2がおすすめ）
- シリアルサーボモータ2個 [Feetech SCS0009](https://www.switch-science.com/products/8042)
- Groveケーブル ([M5Stack用5cm](https://www.switch-science.com/products/8664)など。すでにM5StackのUNITなどで余っているものがあればそれでもOK）
- 筐体（※準備中）／参考：["タカオ版"の筐体一式](https://mongonta.booth.pm/)、または[それの3Dデータ](https://github.com/meganetaaan/stack-chan/tree/dev/v1.0/case/contributed/mongonta_case_for_SG90_and_M5GoBottomBoard)を3Dプリント出力したものと必要なネジ類


## 使い方

※これはタカオ版の組み立て手順です。基本的には同じですが、SCS0009用筐体が公開された後で更新します。

- 筐体の組み立てなどは、[タカオさんの手順](https://raspberrypi.mongonta.com/how-to-build-easy-stackchan-m5gobottom/)を参考に行います。
- M5Stack本体と本ボードはGroveケーブルで接続します
- 2個のサーボを本ボードに接続します。ボード上の「H1」側には水平方向（足側）のサーボを、「V2」側には上下方向（筐体側）のサーボを接続します。いずれも、サーボのGND側（茶色や黒のケーブル側）を、本ボードの端側（白マークのある側）に挿し込みます。
- 本ボードを、Bracket（サーボを固定している部品）に収めます。必要に応じて両面テープやネジなどで固定してください。


## シリアルサーボSCS0009の設定

Feetech社のシリアルサーボSCS0009は、専用設定ツール[FD](https://gitee.com/ftservo/fddebug)を使ってIDや各種パラメータを設定することができます。特に今回のように2個のSCS0009を別々に使用する場合はそれぞれにIDを設定する必要があります。IDの初期値は1ですので、1つのSCC0009のIDを2に設定する必要があります。SCS0009の設定には[純正のボードFE-URT-1](https://akizukidenshi.com/catalog/g/gM-16295/)を使うこともできますが、このStack-chan_TakaoBaSE_SCS0009は簡易的に設定をするための回路が組み込まれています。ただし簡易的な回路のため、設定の読み出し・書き込みに失敗することもありますので、うまく読み出し・書き込みができない場合は、何度かリトライしてください。

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/config0.jpg" width="240px">

M5Stack(Basic/Core2)、本ボード、IDを変更するSCS0009（どちらのコネクタでもOK）を接続する。M5Stackには、設定用プログラムを書き込んでおく。（フォルダSCS0009testをVisualStudioCodeで開き、PlatformIOでビルド・書き込みする。必要に応じてplatformio.iniのボード指定を変更する（標準ではCore2用で、[env]内のdefault_envsで切り替え可能））

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/config1.png" width="240px">

M5StackをPCに接続し、BaudRateを115,200を選んでそのCOMポートを開く。その後、”Search"を押すと、接続されているSCS0009が現れる（※出てこない場合はリトライしたり、USBケーブル抜き差しやM5Stackのリセット後にリトライする）

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/config2.png" width="240px">

ID=1のSCS0009が見つかるはずなので、それを選択し、"Progamming"タブ内を開く。その中の"5.ID"を選ぶと、右下にIDを設定するボックスが現れるので、ここに"2"を入力して"Save"する。

<img src="https://github.com/akita11/Stack-chan_Takao_Base_SCS0009/blob/main/config3.png" width="240px">

正しくIDが設定されればOK。念のため再度"Search"して、ID=2のSCS0009が見つかることを確認する。設定エラーが出る場合はリトライする。



## Author

Junichi Akita (akita@ifdl.jp, @akita11)



