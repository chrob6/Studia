-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Czas generowania: 23 Mar 2020, 16:17
-- Wersja serwera: 5.5.62-0+deb8u1
-- Wersja PHP: 5.6.40-0+deb8u7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Baza danych: `marchro`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Dziekan`
--

CREATE TABLE IF NOT EXISTS `Dziekan` (
`DziekanID` int(11) NOT NULL,
  `PracownikID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `GrupaZajeciowa`
--

CREATE TABLE IF NOT EXISTS `GrupaZajeciowa` (
`GrupaZajeciowaID` int(11) NOT NULL,
  `nr_gr` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Grupoprzedmiot`
--

CREATE TABLE IF NOT EXISTS `Grupoprzedmiot` (
`GrupoprzedmiotID` int(11) NOT NULL,
  `GrupaZajeciowaID` int(11) DEFAULT NULL,
  `PrzedmiotID` int(11) DEFAULT NULL,
  `PracownikID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Ocena`
--

CREATE TABLE IF NOT EXISTS `Ocena` (
`OcenaID` int(11) NOT NULL,
  `Wartosc` decimal(2,1) DEFAULT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `PrzedmiotID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `PracaDyplomowa`
--

CREATE TABLE IF NOT EXISTS `PracaDyplomowa` (
`PracaDyplomowaID` int(11) NOT NULL,
  `nazwapracy` varchar(255) DEFAULT NULL,
  `StudentID` int(11) DEFAULT NULL,
  `RecenzentID` int(11) DEFAULT NULL,
  `PromotorID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Pracownik`
--

CREATE TABLE IF NOT EXISTS `Pracownik` (
`PracownikID` int(11) NOT NULL,
  `tytul` varchar(255) DEFAULT NULL,
  `Imie` varchar(255) DEFAULT NULL,
  `Nazwisko` varchar(255) DEFAULT NULL,
  `WydzialID` int(11) DEFAULT NULL,
  `pracaWydzial` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Promotor`
--

CREATE TABLE IF NOT EXISTS `Promotor` (
`PromotorID` int(11) NOT NULL,
  `PracownikID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Przedmiot`
--

CREATE TABLE IF NOT EXISTS `Przedmiot` (
`PrzedmiotID` int(11) NOT NULL,
  `nazwa` varchar(255) DEFAULT NULL,
  `WydzialID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Recenzent`
--

CREATE TABLE IF NOT EXISTS `Recenzent` (
`RecenzentID` int(11) NOT NULL,
  `PracownikID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Rezerwacja`
--

CREATE TABLE IF NOT EXISTS `Rezerwacja` (
`RezerwacjaID` int(11) NOT NULL,
  `godzina_rez` datetime DEFAULT NULL,
  `SalaID` int(11) DEFAULT NULL,
  `dzienTygodnia` enum('Pon','Wt','Sr','Czw','Pt','So','Nd') DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Sala`
--

CREATE TABLE IF NOT EXISTS `Sala` (
`SalaID` int(11) NOT NULL,
  `nrSali` int(11) DEFAULT NULL,
  `TypSali` enum('audytoryjna','wykladowa','komputerowa') DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Student`
--

CREATE TABLE IF NOT EXISTS `Student` (
  `StudentID` int(11) NOT NULL,
  `Imie` varchar(255) DEFAULT NULL,
  `Nazwisko` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `GrupaZajeciowaID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Wydzial`
--

CREATE TABLE IF NOT EXISTS `Wydzial` (
`WydzialID` int(11) NOT NULL,
  `nazwa` varchar(45) DEFAULT NULL,
  `DziekanID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `Zajecia`
--

CREATE TABLE IF NOT EXISTS `Zajecia` (
`ZajeciaID` int(11) NOT NULL,
  `nr_zajec` int(11) DEFAULT NULL,
  `GrupoPrzedmiotID` int(11) DEFAULT NULL,
  `TematZajec` varchar(255) DEFAULT NULL,
  `RezerwacjaID` int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=latin1;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indexes for table `Dziekan`
--
ALTER TABLE `Dziekan`
 ADD PRIMARY KEY (`DziekanID`), ADD KEY `fk_PracownikDziekan` (`PracownikID`);

--
-- Indexes for table `GrupaZajeciowa`
--
ALTER TABLE `GrupaZajeciowa`
 ADD PRIMARY KEY (`GrupaZajeciowaID`);

--
-- Indexes for table `Grupoprzedmiot`
--
ALTER TABLE `Grupoprzedmiot`
 ADD PRIMARY KEY (`GrupoprzedmiotID`), ADD KEY `fk_GrupaZajeciowaGrupoPrzedmiot` (`GrupaZajeciowaID`), ADD KEY `fk_PrzedmiotGrupoPrzedmiot` (`PrzedmiotID`), ADD KEY `fk_PracownikGrupoPrzedmiot` (`PracownikID`);

--
-- Indexes for table `Ocena`
--
ALTER TABLE `Ocena`
 ADD PRIMARY KEY (`OcenaID`), ADD KEY `fk_StudentOcena` (`StudentID`), ADD KEY `fk_przedmiotOcena` (`PrzedmiotID`);

--
-- Indexes for table `PracaDyplomowa`
--
ALTER TABLE `PracaDyplomowa`
 ADD PRIMARY KEY (`PracaDyplomowaID`), ADD KEY `fk_PracaDyplomowaStudent` (`StudentID`), ADD KEY `fk_PracaDyplomowaRecenzent` (`RecenzentID`), ADD KEY `fk_PracaDyplomowaPromotor` (`PromotorID`);

--
-- Indexes for table `Pracownik`
--
ALTER TABLE `Pracownik`
 ADD PRIMARY KEY (`PracownikID`), ADD KEY `fk_PracownikWydzial` (`WydzialID`);

--
-- Indexes for table `Promotor`
--
ALTER TABLE `Promotor`
 ADD PRIMARY KEY (`PromotorID`), ADD KEY `fk_PromotorPracownik` (`PracownikID`);

--
-- Indexes for table `Przedmiot`
--
ALTER TABLE `Przedmiot`
 ADD PRIMARY KEY (`PrzedmiotID`), ADD KEY `fk_PrzedmiotWydzial` (`WydzialID`);

--
-- Indexes for table `Recenzent`
--
ALTER TABLE `Recenzent`
 ADD PRIMARY KEY (`RecenzentID`), ADD KEY `fk_RecenzentPracownik` (`PracownikID`);

--
-- Indexes for table `Rezerwacja`
--
ALTER TABLE `Rezerwacja`
 ADD PRIMARY KEY (`RezerwacjaID`), ADD KEY `fk_SalaRezerwacja` (`SalaID`);

--
-- Indexes for table `Sala`
--
ALTER TABLE `Sala`
 ADD PRIMARY KEY (`SalaID`);

--
-- Indexes for table `Student`
--
ALTER TABLE `Student`
 ADD PRIMARY KEY (`StudentID`), ADD KEY `fk_StudentGrupaZajeciowa` (`GrupaZajeciowaID`);

--
-- Indexes for table `Wydzial`
--
ALTER TABLE `Wydzial`
 ADD PRIMARY KEY (`WydzialID`), ADD KEY `fk_WydzialDziekan` (`DziekanID`);

--
-- Indexes for table `Zajecia`
--
ALTER TABLE `Zajecia`
 ADD PRIMARY KEY (`ZajeciaID`), ADD KEY `fk_GrupoPrzedmiotZajecia` (`GrupoPrzedmiotID`), ADD KEY `fk_ZajeciaRezerwacja` (`RezerwacjaID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `Dziekan`
--
ALTER TABLE `Dziekan`
MODIFY `DziekanID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `GrupaZajeciowa`
--
ALTER TABLE `GrupaZajeciowa`
MODIFY `GrupaZajeciowaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Grupoprzedmiot`
--
ALTER TABLE `Grupoprzedmiot`
MODIFY `GrupoprzedmiotID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Ocena`
--
ALTER TABLE `Ocena`
MODIFY `OcenaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `PracaDyplomowa`
--
ALTER TABLE `PracaDyplomowa`
MODIFY `PracaDyplomowaID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Pracownik`
--
ALTER TABLE `Pracownik`
MODIFY `PracownikID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Promotor`
--
ALTER TABLE `Promotor`
MODIFY `PromotorID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Przedmiot`
--
ALTER TABLE `Przedmiot`
MODIFY `PrzedmiotID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Recenzent`
--
ALTER TABLE `Recenzent`
MODIFY `RecenzentID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Rezerwacja`
--
ALTER TABLE `Rezerwacja`
MODIFY `RezerwacjaID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=27;
--
-- AUTO_INCREMENT dla tabeli `Sala`
--
ALTER TABLE `Sala`
MODIFY `SalaID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT dla tabeli `Wydzial`
--
ALTER TABLE `Wydzial`
MODIFY `WydzialID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT dla tabeli `Zajecia`
--
ALTER TABLE `Zajecia`
MODIFY `ZajeciaID` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=23;
--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `Dziekan`
--
ALTER TABLE `Dziekan`
ADD CONSTRAINT `fk_PracownikDziekan` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);

--
-- Ograniczenia dla tabeli `Grupoprzedmiot`
--
ALTER TABLE `Grupoprzedmiot`
ADD CONSTRAINT `fk_PracownikGrupoPrzedmiot` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`),
ADD CONSTRAINT `fk_GrupaZajeciowaGrupoPrzedmiot` FOREIGN KEY (`GrupaZajeciowaID`) REFERENCES `GrupaZajeciowa` (`GrupaZajeciowaID`),
ADD CONSTRAINT `fk_PrzedmiotGrupoPrzedmiot` FOREIGN KEY (`PrzedmiotID`) REFERENCES `Przedmiot` (`PrzedmiotID`);

--
-- Ograniczenia dla tabeli `Ocena`
--
ALTER TABLE `Ocena`
ADD CONSTRAINT `fk_przedmiotOcena` FOREIGN KEY (`PrzedmiotID`) REFERENCES `Przedmiot` (`PrzedmiotID`),
ADD CONSTRAINT `fk_StudentOcena` FOREIGN KEY (`StudentID`) REFERENCES `Student` (`StudentID`);

--
-- Ograniczenia dla tabeli `PracaDyplomowa`
--
ALTER TABLE `PracaDyplomowa`
ADD CONSTRAINT `fk_PracaDyplomowaPromotor` FOREIGN KEY (`PromotorID`) REFERENCES `Promotor` (`PromotorID`),
ADD CONSTRAINT `fk_PracaDyplomowaRecenzent` FOREIGN KEY (`RecenzentID`) REFERENCES `Recenzent` (`RecenzentID`),
ADD CONSTRAINT `fk_PracaDyplomowaStudent` FOREIGN KEY (`StudentID`) REFERENCES `Student` (`StudentID`);

--
-- Ograniczenia dla tabeli `Pracownik`
--
ALTER TABLE `Pracownik`
ADD CONSTRAINT `fk_PracownikWydzial` FOREIGN KEY (`WydzialID`) REFERENCES `Wydzial` (`WydzialID`);

--
-- Ograniczenia dla tabeli `Promotor`
--
ALTER TABLE `Promotor`
ADD CONSTRAINT `fk_PromotorPracownik` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);

--
-- Ograniczenia dla tabeli `Przedmiot`
--
ALTER TABLE `Przedmiot`
ADD CONSTRAINT `fk_PrzedmiotWydzial` FOREIGN KEY (`WydzialID`) REFERENCES `Wydzial` (`WydzialID`);

--
-- Ograniczenia dla tabeli `Recenzent`
--
ALTER TABLE `Recenzent`
ADD CONSTRAINT `fk_RecenzentPracownik` FOREIGN KEY (`PracownikID`) REFERENCES `Pracownik` (`PracownikID`);

--
-- Ograniczenia dla tabeli `Rezerwacja`
--
ALTER TABLE `Rezerwacja`
ADD CONSTRAINT `fk_SalaRezerwacja` FOREIGN KEY (`SalaID`) REFERENCES `Sala` (`SalaID`);

--
-- Ograniczenia dla tabeli `Student`
--
ALTER TABLE `Student`
ADD CONSTRAINT `fk_StudentGrupaZajeciowa` FOREIGN KEY (`GrupaZajeciowaID`) REFERENCES `GrupaZajeciowa` (`GrupaZajeciowaID`);

--
-- Ograniczenia dla tabeli `Wydzial`
--
ALTER TABLE `Wydzial`
ADD CONSTRAINT `fk_WydzialDziekan` FOREIGN KEY (`DziekanID`) REFERENCES `Dziekan` (`DziekanID`);

--
-- Ograniczenia dla tabeli `Zajecia`
--
ALTER TABLE `Zajecia`
ADD CONSTRAINT `fk_ZajeciaRezerwacja` FOREIGN KEY (`RezerwacjaID`) REFERENCES `Rezerwacja` (`RezerwacjaID`),
ADD CONSTRAINT `fk_GrupoPrzedmiotZajecia` FOREIGN KEY (`GrupoPrzedmiotID`) REFERENCES `Grupoprzedmiot` (`GrupoprzedmiotID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
