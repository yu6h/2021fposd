#include"../text.h"
#include"../paragraph.h"
#include"../list_item.h"
#include"html_visitor.h"

void HtmlVisitor::visitListItem(ListItem* li) {
    _text.append(li->getHtml());
}

void HtmlVisitor::visitText(Text* t) {
    _text.append(t->getHtml());
}

void HtmlVisitor::visitParagraph(Paragraph* p) {
    Iterator* it = p->createIterator();
    _text.append("<div>");

    _text.append(p->getHtml());
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
    _text.append("</div>");
}
std::string HtmlVisitor::getResult() const {
    return _text;
}

