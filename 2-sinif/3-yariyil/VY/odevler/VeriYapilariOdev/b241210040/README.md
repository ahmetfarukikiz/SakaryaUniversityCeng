## Program _getch() ile çalışır enter tuşuna basılmasına gerek yoktur.

## Verileri Kaydetme Hakkında:
* Program k tuşuna basılırsa kaydedilir bunun dışında x tuşuna basılırsa otomatik kaydedilir ve program kapanır.
	
* Eğer program, terminalin aniden kapatılması veya farklı bir hata nedeniyle çıkış tuşuna basılmadan sonlandırılırsa
* tekrar açılıp dosyadan oku seçeneğine basıldığında bir önceki kaydedilen program çalışacaktır. 

## Caps Lock:
* Her char için 2 case yazılmıştır dolayısıyla hem büyük hem küçük harf menüde işe yarayacaktır.

## Takılı Kalma:
* Tuşlara kısa sürede çok hızlıca basılır veya basılı tutulursa program sonsuz döngüye girmez fakat belli bir süre aynı şeyi tekrarlamaya devam eder sonrasında kendiliğinden düzelir.

## Derleme ve Çalıştırma: 
	mingw32-make hepsi -> hem derler hem çalıştırır
	mingw32-make derle -> sadece derler
	mingw32-make calistir -> sadece çalıştırır