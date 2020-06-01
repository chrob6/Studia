-- wprowadzenie rekordow do tabel
INSERT INTO Sala(nrSali, TypSali) VALUES (402, 'audytoryjna');
INSERT INTO Sala(nrSali, TypSali) VALUES (301, 'Wykladowa');

INSERT INTO Rezerwacja(godzina_rez, SalaID, dzienTygodnia) VALUES ('12-03-20 10:00:00 AM', 1, "Pon");
INSERT INTO Rezerwacja(godzina_rez, SalaID, dzienTygodnia) VALUES ('12-03-20 12:00:00 AM', 2, "Wt");

INSERT INTO Zajecia(nr_zajec, GrupoPrzedmiotID, TematZajec, RezerwacjaID) VALUES(2, 2, "Metale", 1);
INSERT INTO Zajecia(nr_zajec, GrupoPrzedmiotID, TematZajec, RezerwacjaID) VALUES(3, 1, "Interfejs BD", 2);
INSERT INTO Zajecia(nr_zajec, GrupoPrzedmiotID, TematZajec, RezerwacjaID) VALUES(4, 1, "Interfejs Web", 1);
INSERT INTO Zajecia(nr_zajec, GrupoPrzedmiotID, TematZajec, RezerwacjaID) VALUES(5, 1, "Interfejs PHP", 2);

INSERT INTO PracaDyplomowa(nazwapracy, StudentID, RecenzentID, PromotorID) VALUES("Bazy Danych w praktyce", 1, 2, 2);
INSERT INTO PracaDyplomowa(nazwapracy, StudentID, RecenzentID, PromotorID) VALUES("Procesy Metalurgiczne", 2, 1, 1);

INSERT INTO Grupoprzedmiot(GrupaZajeciowaID, PrzedmiotID, PracownikID) VALUES(1,2,2);
INSERT INTO Grupoprzedmiot(GrupaZajeciowaID, PrzedmiotID, PracownikID) VALUES(1,1,1);
INSERT INTO Grupoprzedmiot(GrupaZajeciowaID, PrzedmiotID, PracownikID) VALUES(2,2,2);
INSERT INTO Grupoprzedmiot(GrupaZajeciowaID, PrzedmiotID, PracownikID) VALUES(2,1,1);

INSERT INTO Pracownik(tytul, Imie, Nazwisko, WydzialID, pracaWydzial) VALUES("prof. dr hab. inż.", "Tadeusz", "Telejko", 1, 2);
INSERT INTO Pracownik(tytul, Imie, Nazwisko, WydzialID, pracaWydzial) VALUES("dr hab. inż.", "Piotr", "Maciol", 1, 2);

INSERT INTO Dziekan(PracownikID) VALUES(1);

INSERT INTO Wydzial(nazwa, DziekanID) VALUES("WIMIIP",1);

INSERT INTO Przedmiot(nazwa,WydzialID) VALUES ("Metalurgia", 1);
INSERT INTO Przedmiot(nazwa,WydzialID) VALUES ("Bazy Danych", 1);
INSERT INTO Przedmiot(nazwa,WydzialID) VALUES ("Sieci komputerowe", 1)

INSERT INTO Ocena(Wartosc,StudentID,PrzedmiotID) VALUES (2.0, 1, 1);
INSERT INTO Ocena(Wartosc,StudentID,PrzedmiotID) VALUES (3.5, 2, 1);
INSERT INTO Ocena(Wartosc,StudentID,PrzedmiotID) VALUES (5.0, 1, 2);
INSERT INTO Ocena(Wartosc,StudentID,PrzedmiotID) VALUES (4.5, 2, 2);


INSERT INTO GrupaZajeciowa(nr_gr) VALUES (1);
INSERT INTO GrupaZajeciowa(nr_gr) VALUES (2);

INSERT INTO Student(Imie,Nazwisko,email,GrupaZajeciowaID) VALUES ("Marcin","Chrobak","chrobam.mar@gmail.com",1);
INSERT INTO Student(Imie,Nazwisko,email,GrupaZajeciowaID) VALUES ("Aleksandra","Baran","alebaran@gmail.com",2);

INSERT INTO Promotor(PracownikID) VALUES (1);
INSERT INTO Promotor(PracownikID) VALUES (2);

INSERT INTO Recenzent(PracownikID) VALUES (1);
INSERT INTO Recenzent(PracownikID) VALUES (2);


-- polecenia napisane aby latwo bylo wrocic do poprzednich stanow w razie pomylek

-- usuwanie kluczy obcych
ALTER TABLE `Dziekan`
DROP FOREIGN KEY `fk_PracownikDziekan`;


ALTER TABLE `Grupoprzedmiot`
DROP FOREIGN KEY `fk_PracownikGrupoPrzedmiot` ,
DROP FOREIGN KEY`fk_GrupaZajeciowaGrupoPrzedmiot`,
DROP FOREIGN KEY `fk_PrzedmiotGrupoPrzedmiot`;


ALTER TABLE `Ocena`
DROP FOREIGN KEY`fk_przedmiotOcena`,
DROP FOREIGN KEY `fk_StudentOcena`;


ALTER TABLE `PracaDyplomowa`
DROP FOREIGN KEY `fk_PracaDyplomowaPromotor`,
DROP FOREIGN KEY `fk_PracaDyplomowaRecenzent`,
DROP FOREIGN KEY `fk_PracaDyplomowaStudent`;

ALTER TABLE `Pracownik`
DROP FOREIGN KEY`fk_PracownikWydzial` ;


ALTER TABLE `Promotor`
DROP FOREIGN KEY `fk_PromotorPracownik`;


ALTER TABLE `Przedmiot`
DROP FOREIGN KEY `fk_PrzedmiotWydzial`;


ALTER TABLE `Recenzent`
DROP FOREIGN KEY `fk_RecenzentPracownik` ;


ALTER TABLE `Rezerwacja`
DROP FOREIGN KEY `fk_SalaRezerwacja` ;


ALTER TABLE `Student`
DROP FOREIGN KEY `fk_StudentGrupaZajeciowa` ;


ALTER TABLE `Wydzial`
DROP FOREIGN KEY `fk_WydzialDziekan`;


ALTER TABLE `Zajecia`
DROP FOREIGN KEY `fk_ZajeciaRezerwacja` ,
DROP FOREIGN KEY `fk_GrupoPrzedmiotZajecia`;

-- dodanie kluczy obcych
ALTER TABLE `Dziekan`
ADD CONSTRAINT `fk_PracownikDziekan` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);


ALTER TABLE `Grupoprzedmiot`
ADD CONSTRAINT `fk_PracownikGrupoPrzedmiot` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`),
ADD CONSTRAINT `fk_GrupaZajeciowaGrupoPrzedmiot` FOREIGN KEY (`GrupaZajeciowaID`) REFERENCES `GrupaZajeciowa` (`GrupaZajeciowaID`),
ADD CONSTRAINT `fk_PrzedmiotGrupoPrzedmiot` FOREIGN KEY (`PrzedmiotID`) REFERENCES `Przedmiot` (`PrzedmiotID`);


ALTER TABLE `Ocena`
ADD CONSTRAINT `fk_przedmiotOcena` FOREIGN KEY (`PrzedmiotID`) REFERENCES `Przedmiot` (`PrzedmiotID`),
ADD CONSTRAINT `fk_StudentOcena` FOREIGN KEY (`StudentID`) REFERENCES `Student` (`StudentID`);


ALTER TABLE `PracaDyplomowa`
ADD CONSTRAINT `fk_PracaDyplomowaPromotor` FOREIGN KEY (`PromotorID`) REFERENCES `Promotor` (`PromotorID`),
ADD CONSTRAINT `fk_PracaDyplomowaRecenzent` FOREIGN KEY (`RecenzentID`) REFERENCES `Recenzent` (`RecenzentID`),
ADD CONSTRAINT `fk_PracaDyplomowaStudent` FOREIGN KEY (`StudentID`) REFERENCES `Student` (`StudentID`);


ALTER TABLE `Pracownik`
ADD CONSTRAINT `fk_PracownikWydzial` FOREIGN KEY (`WydzialID`) REFERENCES `Wydzial` (`WydzialID`);


ALTER TABLE `Promotor`
ADD CONSTRAINT `fk_PromotorPracownik` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);


ALTER TABLE `Przedmiot`
ADD CONSTRAINT `fk_PrzedmiotWydzial` FOREIGN KEY (`WydzialID`) REFERENCES `Wydzial` (`WydzialID`);


ALTER TABLE `Recenzent`
ADD CONSTRAINT `fk_RecenzentPracownik` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);


ALTER TABLE `Rezerwacja`
ADD CONSTRAINT `fk_SalaRezerwacja` FOREIGN KEY (`SalaID`) REFERENCES `Sala` (`SalaID`);


ALTER TABLE `Student`
ADD CONSTRAINT `fk_StudentGrupaZajeciowa` FOREIGN KEY (`GrupaZajeciowaID`) REFERENCES `GrupaZajeciowa` (`GrupaZajeciowaID`);


ALTER TABLE `Wydzial`
ADD CONSTRAINT `fk_WydzialDziekan` FOREIGN KEY (`DziekanID`) REFERENCES `Dziekan` (`DziekanID`);


ALTER TABLE `Zajecia`
ADD CONSTRAINT `fk_ZajeciaRezerwacja` FOREIGN KEY (`RezerwacjaID`) REFERENCES `Rezerwacja` (`RezerwacjaID`),
ADD CONSTRAINT `fk_GrupoPrzedmiotZajecia` FOREIGN KEY (`GrupoPrzedmiotID`) REFERENCES `Grupoprzedmiot` (`GrupoprzedmiotID`);


-- usuniecie danych z tabeli
TRUNCATE TABLE Dziekan;
TRUNCATE TABLE GrupaZajeciowa;
TRUNCATE TABLE Grupoprzedmiot;
TRUNCATE TABLE Ocena;
TRUNCATE TABLE PracaDyplomowa;
TRUNCATE TABLE Pracownik;
TRUNCATE TABLE Promotor;
TRUNCATE TABLE Przedmiot;
TRUNCATE TABLE Recenzent;
TRUNCATE TABLE Rezerwacja;
TRUNCATE TABLE Sala;
TRUNCATE TABLE Student;
TRUNCATE TABLE Wydzial;
TRUNCATE TABLE Zajecia;

-- 1a
INSERT INTO Ocena(Wartosc,StudentID,PrzedmiotID) VALUES (4.0, 2, 1);
UPDATE Ocena SET Wartosc=3.5 WHERE OcenaID = 1;

-- 1b
UPDATE Rezerwacja SET dzienTygodnia = "Sr" WHERE RezerwacjaID = 2;
UPDATE Rezerwacja SET SalaID = 2 WHERE RezerwacjaID =1;

-- 1c
UPDATE Grupoprzedmiot SET PracownikID = 2 WHERE GrupoprzedmiotID = 2;

-- 1d
UPDATE Student SET email="chrobak.mar6@gmail.com" WHERE StudentID = 1;

-- 1e
INSERT INTO Student(Imie,Nazwisko,email,GrupaZajeciowaID) VALUES ("Jolanta","Chrobak","jchrobak@gmail.com",1);
INSERT INTO Pracownik(tytul, Imie, Nazwisko, WydzialID, pracaWydzial) VALUES("mgr inż.", "Piotr", "Hajder", 1, 0);

-- 1f
DELETE FROM Zajecia WHERE GrupoprzedmiotID = 1;
DELETE FROM Grupoprzedmiot WHERE PrzedmiotID = 1;
DELETE FROM Ocena WHERE PrzedmiotID = 1;
DELETE FROM Przedmiot WHERE PrzedmiotID = 1;

-- 1g
UPDATE Student SET GrupaZajeciowaID = 1 WHERE GrupaZajeciowaID = 2;
UPDATE Grupoprzedmiot SET GrupaZajeciowaID = 1 WHERE GrupaZajeciowaID = 2;
DELETE FROM GrupaZajeciowa WHERE GrupaZajeciowaID = 2;

-- 1h -- problem z usunieciem - zapetlone klucze, najprawdopodobniej zle ulozona struktura
DELETE FROM Wydzial WHERE WydzialID = 1;
DELETE FROM Dziekan WHERE PracownikID = 1;
DELETE FROM Pracownik WHERE WydzialID = 1;

-- 1i -- w strukturze tabeli nie uwzglednilem numeru semestru
SELECT nazwa FROM Przedmiot ORDER BY nazwa;

-- 1j
SELECT  * from Zajecia WHERE TematZajec LIKE "%Interfejs%" ORDER BY nr_zajec;