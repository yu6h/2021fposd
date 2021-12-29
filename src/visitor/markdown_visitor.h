#pragma once
#include"article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li)override {
    _text.append(li->getText());
    }
    void visitText(Text* t) override{
    _text.append(t->getText());
    }

    void visitParagraph(Paragraph* p) override{
    _text.append(p->getText()).append("\n");
    }
    // std::string getResult() const override { }
};