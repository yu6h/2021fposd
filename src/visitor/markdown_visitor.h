#pragma once
#include"article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li)override;

    void visitText(Text* t) override;

    void visitParagraph(Paragraph* p) override;


};