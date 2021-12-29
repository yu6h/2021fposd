#pragma once
#include"./article_visitor.h"

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override {
    _text.append("<li>");
    _text.append(li->getTextAttribute());
    _text.append("</li>");
    }

    void visitText(Text* t) override  {
    _text.append("<span>");
    _text.append(t->getTextAttribute());
    _text.append("</span>");
    }

    void visitParagraph(Paragraph* p) override {
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

    // std::string getResult() const override { }
};