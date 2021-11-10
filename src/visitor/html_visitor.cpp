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
    int level = p->getLevel();
    _text.append("<h");
    switch (level)
    {
    case 1:
        _text.append("1");
        break;
    case 2:
        _text.append("2");
        break;
    case 3:
        _text.append("3");
        break;
    case 4:
        _text.append("4");
        break;
    case 5:
        _text.append("5");
        break;
    case 6:
        _text.append("6");
        break;
    default:
        break;
    }
    _text.append(">");
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
    _text.append("</div>");
    _text.append("</h");
    switch (level)
    {
    case 1:
        _text.append("1");
        break;
    case 2:
        _text.append("2");
        break;
    case 3:
        _text.append("3");
        break;
    case 4:
        _text.append("4");
        break;
    case 5:
        _text.append("5");
        break;
    case 6:
        _text.append("6");
        break;
    default:
        break;
    }
    _text.append(">");
}
std::string HtmlVisitor::getResult() const {
    return _text;
}

