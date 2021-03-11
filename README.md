# em-2_mount
EM-2赤道儀在電路板故障後，自行製造替代用的實驗型電路板  
[Hackmd.io![hackmd-github-sync-badge](https://hackmd.io/sIzvRXmRRlCRxG6UBYnCwA/badge)](https://hackmd.io/sIzvRXmRRlCRxG6UBYnCwA)  
[Github![github](https://icons-for-free.com/iconfiles/png/128/part+1+github-1320568339880199515.png)](https://github.com/nelson40514/em-2_mount)

## 系統發展背景
舊有之EM-2赤道儀無法正常運轉，在對內部進行簡易檢修後發現舊有之電路已無法正常運作<small>(在適當架設後，以社窩之示波器檢測電路板輸出至步進馬達的訊號，發現未能有適當之脈衝波進行輸出)</small>。  
因測試初期對電路板元件之檢修較不具專業知識，故將電路板與步進馬達之連接直接移除，而在[香港天文論壇](http://www.hkastroforum.net/viewtopic.php?t=5353 )網頁中查到的資料中得知，EM-2赤道儀所使用之步進馬達P-43G有六條接線(兩條正極四條phase)，其中四條phase兩兩互接電阻應為$140\Omega$，而與正極互接應為$140\Omega$，如有短路<small>(接點損毀)</small>或斷路<small>(燒斷)</small>即為馬達損壞，所幸在測試後發現馬達安好<small>(因為在Ebay上看到P-43G的價錢超過兩千台幣且僅為零件<small><del>太貴了</del></small>，如果需要將齒輪組全部拆下再安裝可能是更困難的工程)</small>。  
在這之後因為維修人員較不具電機電子電路背景，便決定要以Arduino開發環境進行修復的嘗試，初期以Arduino nano板及麵包板透過極淺顯易懂的原型便順利讓赤道儀再度轉動。  
而在逐漸將轉動速度設定的更為精確時卻發現赤經軸之剛性不足，因此無法獲得更高的精度，且麵包板無法置於赤道儀。
## 目前系統
目前之電路設計為以Atmel所出產的[Attiny45](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf)這個MCU作為核心之體積縮小版電路，而此小型電路以Attiny45主為主控但是沒有以石英晶震做時脈產生，而是內建之震盪電路，所以速度誤差可能會較大。但是因為社上尚有EM-200作為主力赤道儀，而此EM-2即便修好也不會作為攝影用途而較可能會以目視教學，且在剛性不足的情況下作為攝影用途也較為困難，因此最後的成品便沒有再增加額外的時脈產生電路了。
:::spoiler 目前系統以EasyEDA渲染之3D模擬圖<small>(按一下展開)</small>
此模擬圖不含接口以及電阻
![](https://github.com/nelson40514/em-2_mount/blob/main/PCB_Layout_3D.png?raw=true)
:::
### 使用方式
#### 電源
:::danger
使用之電源極性已做更動，不可與原本EM-2之輸入電源共用。
:::
目前電源為內正外負之較為普遍的DC直流電源接口，正常使用確保正負極即可。
* 內徑2.1mm
* 外徑5.5mm
* 電壓7V~12V
* 其他
    * 因採用線性穩壓器，多餘電壓會轉變為熱量
      電壓如太高且高電流可能會導致晶片燒毀
    * 可採用12V電瓶供電
    * 如不甚反接電壓 $\le$ 8V應該會沒事
    * 如果超過8V趕快拔掉，還沒聞到燒焦味的話可能還能用
#### 操作
在接上電源後即開始轉動，沒有設計開關  
電源指示燈會每2s變換明暗，即週期為4s
## 目前硬體架構
以EasyEDA繪製之電路圖
{%pdf https://github.com/nelson40514/em-2_mount/blob/main/PCB_Layout.pdf?raw=true %}
### 電源供應 7805
### 時脈產生 Attiny45
### 馬達驅動 ULN2003
### 燒錄

## 參考資料
[46th幹部群、石虎撰寫之前代修復EM-2文件](https://docs.google.com/document/d/19kICd7o-TUf18zYF089fwOmUeDHLzgfi/edit)  
[香港天文論壇](http://www.hkastroforum.net/viewtopic.php?t=5353 ):研究初期提供我們許多有用的資料  
[日文網站](http://7l1wqg.jp/article/187443705.html):最近發現的，可能之後會有用  
[7805線性穩壓IC](https://zh.wikipedia.org/wiki/78xx)  
#### [P-43G步進馬達](https://github.com/nelson40514/em-2_mount/blob/main/K-P43G.pdf)
* 電壓12V
* 電阻70$\Omega$
* 為24階(24 step)
* phase線順序
    1. 白
    2. 藍
    3. 黑
    4. 黃
### Datasheet
[TC5048Pdatasheet](http://pdf.datasheetcatalog.com/datasheet_pdf/toshiba/TC5036P_and_TC5048P.pdf)  
[Attiny45](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf)

#### 聯絡資訊<address>s106021109@m106.nthu.edu.tw</address>  