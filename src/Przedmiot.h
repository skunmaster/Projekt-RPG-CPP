#pragma once
#include <string>
#include <iostream>

enum class Kategoria {
    MIKSTURA,
    ZYWNOSC,
    ZWOJ
};

class Przedmiot {
    private:
        std::string nazwa;
        Kategoria kategoria;
        int leczenie, obrazenia, ilosc;

    public:
        Przedmiot();
        Przedmiot(const std::string& n, Kategoria kat, int lecz, int obr, int ilo);

        std::string getNazwa() const;
        Kategoria getKategoria() const;
        int getLeczenie() const;
        int getObrazenia() const;
        int getIlosc() const;
        
        void setIlosc(int nowaIlosc);
        void setLeczenie(int noweLeczenie);
        void setObrazenia(int noweObrazenia);

        bool operator==(const Przedmiot& inny) const;
        friend std::ostream& operator<<(std::ostream& os, const Przedmiot& p);
};

