#include "Przedmiot.h"
#include <stdexcept>

Przedmiot::Przedmiot()
    : nazwa("Brak"), kategoria(Kategoria::MIKSTURA), leczenie(0), obrazenia(0), ilosc(0) {}

Przedmiot::Przedmiot(const std::string& n, Kategoria kat, int lecz, int obr, int il)
    : nazwa(n), kategoria(kat), leczenie(lecz), obrazenia(obr), ilosc(il) {
        if (nazwa.empty()){
            throw std::invalid_argument("Nazwa przedmiotu nie moze byc pusta");
        }
        if (leczenie < 0){
            throw std::invalid_argument("Leczenie nie moze byc ujemne");
        }
        if (obrazenia < 0){
            throw std::invalid_argument("Obrazenia nie moga byc ujemne");
        }
        if (ilosc < 0){
            throw std::invalid_argument("Ilosc nie moze byc ujemna");
        }

}

std::string Przedmiot::getNazwa() const{
    return nazwa;
}

Kategoria Przedmiot::getKategoria() const{
    return kategoria;
}

int Przedmiot::getLeczenie() const{
    return leczenie;
}

int Przedmiot::getObrazenia() const{
    return obrazenia;
}

bool Przedmiot::operator==(const Przedmiot& inny) const{
    return nazwa == inny.nazwa;
}

void Przedmiot::setIlosc(int nowaIlosc){
    if (nowaIlosc < 0) {
        throw std::invalid_argument("ilosc nie moze byc ujemna");
    }
    ilosc = nowaIlosc;
}

void Przedmiot::setLeczenie(int noweLeczenie){
    if (noweLeczenie < 0) {
        throw std::invalid_argument("leczenie nie moze byc ujemna");
    }
    leczenie = noweLeczenie;
}

void Przedmiot::setObrazenia(int noweObrazenia){
    if (noweObrazenia < 0) {
        throw std::invalid_argument("obrazenia nie moze byc ujemna");
    }
    obrazenia = noweObrazenia;
}



std::ostream& operator<<(std::ostream& os, const Przedmiot& p){
    std::string nazwaKat;
    switch(p.kategoria) {
        case Kategoria::MIKSTURA: nazwaKat = "MIKSTURA"; break;
        case Kategoria::ZYWNOSC: nazwaKat = "ZYWNOSC"; break;
        case Kategoria::ZWOJ: nazwaKat = "ZWOJ"; break;
    }
    os << p.nazwa << " [" << nazwaKat << "] - ";
    if (p.leczenie > 0) { 
        os << p.leczenie << " punktow zdrowia - ";
        }
    if (p.obrazenia > 0) { 
        os << p.obrazenia << " punktow obrazen";
        }
    if (p.ilosc > 0) { 
        os << "(x" << p.ilosc << ")";
        }
        
    return os;
}