/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-05: Leia õige viit
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

int main() {
	// Oletame, et meil on järgnev kood
	int k, m;
	int* p;
	k = 16;
	m = k;
	p = &k;

	// Millise käsu / milliste käskude tulemusel on muutuja k väärtuseks 48?
	// Miks? Mis on teiste käskude tulemuseks?
	// m *= 3; // A
	// *m *= 3; // B
	// p *= 3; // C
	// *p *= 3; // D

	// Esiteks vaatleme, mis esialgses koodis toimub.

	// Deklareerime täisarvu tüüpi (int) muutujad k ja m. Algväärtustamine
	// puudub, st neis asuvad prügiväärtused, mis mõne teise programmi tööst
	// arvuti mällu on jäänud.
	//   int k, m;
	// Seejärel deklareerime viitmuutuja, mis viitab täisarvu tüüpi muutujale.
	// Taas puudub algväärtustamine, st muutujas asub prügiväärtus, mis mõne
	// teise programmi tööst arvuti mällu on jäänud. Tegelikult peaks siin
	// muutuja algväärtustama tühiviidaga nullptr, sest vastasel juhul võime
	// kogemata kasutada mõne teise programmi mälu.
	//   int* p;
	// Nüüd omistame muutujale k väärtuse 16. Ühegi teise muutuja väärtus selle
	// tulemusel ei muutu.
	//   k = 16;
	// Seejärel omistame muutujale m muutuja k väärtuse. Kõigepealt leitakse
	// omistuslause parempoolse avaldise väärtus ning seejärel omistatakse see
	// väärtus vahetult vasakul pool asuvasse muutujasse. Muutuja m väärtus on
	// nüüd samuti 16, nagu muutujal k. Samas ei ole muutujad omavahel seotud,
	// st neist ühe väärtust muutes teise väärtus ei muutu.
	//   m = k;
	// Lõpuks leiame muutuka k mäluaadressi ja omistame selle viitmuutuja p
	// väärtuseks. Nüüd saab muutuja p väärtuse kaudu ligi pääseda ka muutuja k
	// väärtusele.
	//   p = &k.

	// Nüüd vaatleme ükshaaval käske A-D ja uurime nende võimalikke tulemusi.

	// Käsk A:
	//   m *= 3;
	//   Muutuja m väärtus korrutatakse 3-ga ja tulemus omistatakse muutuja m
	//   uueks väärtuseks, st muutuja m väärtus on nüüd 16 * 3 = 48. Kuna
	//   muutujad k ja p pole kuidagi muutujaga m seotud, siis neid see tehe
	//   kuidagi ei mõjuta.

	// Käsk B:
	//   *m *= 3;
	//   Kui muutuja ette panna *, käsitletakse selle väärtust mäluaadressina ja
	//   üritatakse arvuti mälust üles leida nimetatud mäluaadressiga muutuja.
	//   Kuna aga muutuja m ei ole viitmuutuja, vaid on täisarvu tüüpi, pole see
	//   loogiline operatsioon ja kompileerimisel väljastatakse selle kohta
	//   veateade.

	// Käsk C:
	//   p *= 3;
	//   Muutuja p väärtust üritatakse 3-ga korrutada ja tulemus muutuja p uueks
	//   väärtuseks omistada. Muutuja p on viitmuutuja, st selle väärtuseks on
	//   mäluaadress. Mäluaadressi korrutamine mingi teise arvuga pole loogiline
	//   operatsioon ja kompileerimisel väljastatakse selle kohta veateade.
	//   Kui korrutustehte asemel oleks siin hoopis liitmine (või lahutamine),
	//   siis kood küll kompileeruks ja veateadet ei väljastataks, aga muutuja p
	//   ei viitaks enam muutujale k, vaid arvuti mälus sellest kolme 4-baidise
	//   mälupesa võrra (kuna int on 4-baidine) paremal (või lahutamise korral
	//   vasakul) asuvale mäluaadressile.

	// Käsk D:
	//   *p *= 3;
	//   Muutuja p väärtust käsitletakse mäluaadressina ja üritatakse arvuti
	//   mälust üles leida nimetatud mäluaadressiga muutuja. Siis korrutatakse
	//   leitud mäluaadressil asuv väärtus 3-ga ja omistatakse uueks väärtuseks.
	//   Viitmuutuja p väärtus on muutuja k mäluaadress, seega korrutatakse siin
	//   tegelikult muutuja k väärtus 3-ga ja omistatakse uueks väärtuseks.

	// Vastus:
	//   Ülaltoodud arutluskäigu tulemusel saab muutuja k väärtuseks 48 ainult
	//   käsu D tulemusel. Käsud B ja C  väljastavad kompileerimisel veateate ja
	//   käsu A tulemusel muutub ainult muutuja m väärtus.

	return 0;
}
