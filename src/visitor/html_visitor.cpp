#include"../text.h"
#include"../paragraph.h"
#include"../list_item.h"
#include"html_visitor.h"

void HtmlVisitor::visitListItem(ListItem* li) {
    _text.append("<li>");
    _text.append(li->getTextAttribute());
    _text.append("</li>");
}

void HtmlVisitor::visitText(Text* t) {
    _text.append("<span>");
    _text.append(t->getTextAttribute());
    _text.append("</span>");
}

void HtmlVisitor::visitParagraph(Paragraph* p) {
    Iterator* it = p->createIterator();
    _text.append("<div>");

    _text.append("<h").append(std::to_string(p->getLevel())).append(">");
    _text.append(p->getTextAttribute());
    _text.append("</h").append(std::to_string(p->getLevel())).append(">");


    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
    delete it;
    _text.append("</div>");
}


