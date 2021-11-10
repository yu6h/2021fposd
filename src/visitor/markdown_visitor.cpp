

#include"markdown_visitor.h"
#include"../text.h"
#include"../paragraph.h"
#include"../list_item.h"


void MarkdownVisitor::visitListItem(ListItem* li) {
    _text.append(li->getText());
};

void MarkdownVisitor::visitText(Text* t) {
    _text.append(t->getText());
};

void MarkdownVisitor::visitParagraph(Paragraph* p){
    Iterator* it = p->createIterator();
    _text.append(p->getText()).append("\n");
};
std::string MarkdownVisitor::getResult() const {
    return _text;
}