#include <iostream>
#include <string>
#include <vector>

class TextFile;
class HighlightVisitor;

class Visitor {
public:
    virtual void visitTextFile(TextFile* file) = 0;
    virtual void visitHighlightVisitor(HighlightVisitor* visitor) = 0;
};

class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

class TextFile : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitTextFile(this);
    }

    void open() {
        std::cout << "Opening text file..." << std::endl;
    }

    void edit() {
        std::cout << "Editing text file..." << std::endl;
    }

    void print() {
        std::cout << "Printing text file..." << std::endl;
    }
};

class HighlightVisitor : public Visitor {
public:
    void visitTextFile(TextFile* file) override {
        file->open();
        file->edit();
        file->print();
    }

    void visitHighlightVisitor(HighlightVisitor* visitor) override {
        std::cout << "Highlighting text file..." << std::endl;
    }
};

int main() {
    TextFile textFile;
    HighlightVisitor highlightVisitor;

    textFile.accept(&highlightVisitor);

    return 0;
}
