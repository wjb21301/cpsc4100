#include <iostream>
class Printer{
    public:
    virtual void print(const std::string& document) = 0;
    virtual ~Printer() = default;
};
class hpPrinter :  public Printer {
    public:
    void print(const std::string& document) override {
        std::cout << "hp printing: " << document << std::endl;
    }
};
class canonPrinter :  public Printer {
    public:
    void print(const std::string& document) override {
        std::cout << "canon printing: " << document << std::endl;
    }
};
void printJob(Printer* printer, const std::string& text){
    printer->print(text);
}
int main(){
    hpPrinter hp;
    canonPrinter can;
    printJob(&hp, "Reports.docx");
    printJob(&can, "Assignment1.docx");
}