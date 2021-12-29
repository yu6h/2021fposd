#pragma once
#include"article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li)override {
    _text.append("- ").append(li->getText()).append("\n");
    }
    void visitText(Text* t) override{
    _text.append(t->getText()).append("\n");
    }

    void visitParagraph(Paragraph* p) override{
        Iterator* it = p->createIterator();
        for(int i=0;i<p->getLevel();i++)_text.append("#");
        _text.append(" ");
        _text.append(p->getText());
        _text.append("\n");

        for (it->first(); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
        }
        delete it;
    }
    // std::string getResult() const override { }
};
    // std::string getText() const override {
    //     std::string textOfParagraph;


    //     for(int i=0;i<_level;i++)textOfParagraph.append("#");
    //     textOfParagraph.append(" ");
    //     textOfParagraph.append(_text);
    //     textOfParagraph.append("\n");

        
    //     for(int i=0;i<int(articles.size());i++){

    //         textOfParagraph.append(articles[i]->getText());

    //         if(i!= int(articles.size())-1)textOfParagraph.append("\n");
    //     }
    //     return textOfParagraph;
    // }