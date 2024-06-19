#include <iostream>
#include <vector>
#include <string>

// ќбъ€вление класса, представл€ющего итератор
class TextEditorIterator {
public:
    TextEditorIterator(std::vector<std::string> text) : text_(text), index_(0) {}

    void first() {
        index_ = 0;
    }

    void next() {
        index_++;
    }

    bool is_done() {
        return index_ >= text_.size();
    }

    std::string current_item() {
        return text_[index_];
    }

private:
    std::vector<std::string> text_;
    size_t index_;
};

//  ласс, представл€ющий текстовый редактор
class TextEditor {
public:
    TextEditor(std::vector<std::string> text) : text_(text) {}

    TextEditorIterator* create_iterator() {
        return new TextEditorIterator(text_);
    }

    void print_text() {
        for (std::string line : text_) {
            std::cout << line << std::endl;
        }
    }

private:
    std::vector<std::string> text_;
};

int main() {
    std::vector<std::string> lines = { "This is a sample text",
                                      "for demonstrating the Text Editor",
                                      "with iterator implementation in C++" };

    TextEditor text_editor(lines);
    TextEditorIterator* iterator = text_editor.create_iterator();

    for (iterator->first(); !iterator->is_done(); iterator->next()) {
        std::cout << iterator->current_item() << std::endl;
    }

    delete iterator;

    return 0;
}