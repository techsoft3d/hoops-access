#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

/* define some colors */
static Vfloat red[3] = {1.f, 0.f, 0.f};
static Vfloat grn[3] = {0.f, 1.f, 0.f};
static Vfloat blu[3] = {0.f, 0.f, 1.f};
static Vfloat blk[3] = {0.f, 0.f, 0.f};
static Vfloat wht[3] = {1.f, 1.f, 1.f};
static Vfloat back[3] = {0.733333f, 0.866666f, 1.0f};
static Vfloat offwht[3] = {0.8f, 0.8f, 0.8f};
static Vfloat altwht[3] = {0.9f, 0.9f, 0.9f};

/*----------------------------------------------------------------------
                      Test and demonstrate TextFun objects
----------------------------------------------------------------------*/
int
main()
{
    vsy_HTMLText* htmltext;
    vsy_PlainText* plaintext;
    vsy_LaTeXText* latextext;
    vsy_TextTee* texttee;
    vsy_TextFun *tf0, *tf1, *tf2, *tf;

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* set HTML output */
    htmltext = vsy_HTMLTextBegin();
    tf0 = vsy_TextFunBegin();
    vsy_HTMLTextTextFun(htmltext, tf0);
    vsy_TextFunOpenFile(tf0, (Vchar*)"exam16.htm");

    /* set plain text output */
    plaintext = vsy_PlainTextBegin();
    tf1 = vsy_TextFunBegin();
    vsy_PlainTextTextFun(plaintext, tf1);
    vsy_TextFunOpenFile(tf1, (Vchar*)"exam16.txt");

    /* set LaTeX output */
    latextext = vsy_LaTeXTextBegin();
    tf2 = vsy_TextFunBegin();
    vsy_LaTeXTextTextFun(latextext, tf2);
    vsy_TextFunOpenFile(tf2, (Vchar*)"exam16.tex");

    /* create a tee to write to all formats */
    texttee = vsy_TextTeeBegin();
    vsy_TextTeeSetObject(texttee, VSY_TEXTFUN, tf0);
    vsy_TextTeeSetObject(texttee, VSY_TEXTFUN_1, tf1);
    vsy_TextTeeSetObject(texttee, VSY_TEXTFUN_2, tf2);
    tf = vsy_TextFunBegin();
    vsy_TextTeeTextFun(texttee, tf);

    /* title */
    vsy_TextFunFormInit(tf, SYS_TEXT_TITLE);
    vsy_TextFunString(tf, "This is the title");
    vsy_TextFunFormTerm(tf, SYS_TEXT_TITLE);

    /* level 1 heading */
    vsy_TextFunHeadingLevel(tf, 1);
    vsy_TextFunFormInit(tf, SYS_TEXT_HEADING);
    vsy_TextFunString(tf, "This is a heading 1 test");
    vsy_TextFunFormTerm(tf, SYS_TEXT_HEADING);

    /* horizontal rule */
    vsy_TextFunHorizontalRule(tf);

    /* level 2 heading */
    vsy_TextFunHeadingLevel(tf, 2);
    vsy_TextFunFormInit(tf, SYS_TEXT_HEADING);
    vsy_TextFunString(tf, "This is a heading 2 test");
    vsy_TextFunFormTerm(tf, SYS_TEXT_HEADING);

    /* basic text */
    vsy_TextFunTextColor(tf, wht);
    vsy_TextFunString(tf, "This is white-colored text.");
    vsy_TextFunTextColor(tf, red);
    vsy_TextFunString(tf, "This is red-colored text.");
    vsy_TextFunTextColor(tf, grn);
    vsy_TextFunString(tf, "This is green-colored text.");
    vsy_TextFunTextColor(tf, blu);
    vsy_TextFunString(tf, "This is blue-colored text.");
    vsy_TextFunTextColor(tf, blk);
    vsy_TextFunString(tf, "And now back to black-colored text.");

    /* list */
    vsy_TextFunListType(tf, SYS_TEXT_ORDERED);
    vsy_TextFunFormInit(tf, SYS_TEXT_LIST);
    vsy_TextFunFormInit(tf, SYS_TEXT_ITEM);
    vsy_TextFunSetMode(tf, SYS_TEXT_BOLD, SYS_ON);
    vsy_TextFunString(tf, "This is item 1 in a list in bold font");
    vsy_TextFunSetMode(tf, SYS_TEXT_BOLD, SYS_OFF);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ITEM);
    vsy_TextFunFormInit(tf, SYS_TEXT_ITEM);
    vsy_TextFunSetMode(tf, SYS_TEXT_ITALICS, SYS_ON);
    vsy_TextFunString(tf, "This is item 2 in a list in italics font");
    vsy_TextFunSetMode(tf, SYS_TEXT_ITALICS, SYS_OFF);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ITEM);
    vsy_TextFunFormInit(tf, SYS_TEXT_ITEM);
    vsy_TextFunSetMode(tf, SYS_TEXT_TYPEWRITER, SYS_ON);
    vsy_TextFunString(tf, "This is item 3 in a list in typewriter font");
    vsy_TextFunSetMode(tf, SYS_TEXT_TYPEWRITER, SYS_OFF);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ITEM);
    vsy_TextFunFormTerm(tf, SYS_TEXT_LIST);

    /* table */
    vsy_TextFunSetMode(tf, SYS_TEXT_CENTER, SYS_ON);
    vsy_TextFunTableWidth(tf, 60);
    vsy_TextFunBorderWidth(tf, 4);
    vsy_TextFunFormInit(tf, SYS_TEXT_TABLE);

    /* row 1 */
    vsy_TextFunFormInit(tf, SYS_TEXT_ROW);
    vsy_TextFunColumnAlign(tf, SYS_TEXT_LEFT);
    vsy_TextFunTableColor(tf, red);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "Aligned left");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunColumnAlign(tf, SYS_TEXT_MIDDLE);
    vsy_TextFunTableColor(tf, grn);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "Aligned middle");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunColumnAlign(tf, SYS_TEXT_RIGHT);
    vsy_TextFunTableColor(tf, blu);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "Aligned right");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ROW);

    /* row 2 */
    vsy_TextFunTableColor(tf, offwht);
    vsy_TextFunFormInit(tf, SYS_TEXT_ROW);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 2 col 1");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 2 col 2");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 2 col 3");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ROW);

    /* row 3 */
    vsy_TextFunTableColor(tf, altwht);
    vsy_TextFunFormInit(tf, SYS_TEXT_ROW);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 3 col 1");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 3 col 2");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormInit(tf, SYS_TEXT_COLUMN);
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunString(tf, "row 3 col 3");
    vsy_TextFunSpace(tf, 3);
    vsy_TextFunFormTerm(tf, SYS_TEXT_COLUMN);
    vsy_TextFunFormTerm(tf, SYS_TEXT_ROW);
    vsy_TextFunTableColor(tf, back);

    vsy_TextFunFormTerm(tf, SYS_TEXT_TABLE);

    /* image file */
    vsy_TextFunFormAction(tf, SYS_TEXT_LINEBREAK);
    vsy_TextFunImageFile(tf, (Vchar*)"../../vgl/exam/earth.gif");
    vsy_TextFunSetMode(tf, SYS_TEXT_CENTER, SYS_OFF);
    vsy_TextFunFormAction(tf, SYS_TEXT_LINEBREAK);

    /* pre-formatted text */
    vsy_TextFunHeadingLevel(tf, 2);
    vsy_TextFunFormInit(tf, SYS_TEXT_HEADING);
    vsy_TextFunString(tf, "Pre-formatted text");
    vsy_TextFunFormTerm(tf, SYS_TEXT_HEADING);
    vsy_TextFunSetMode(tf, SYS_TEXT_PREFORMATTED, SYS_ON);
    vsy_TextFunString(tf, "j = 0;\n");
    vsy_TextFunString(tf, "for(i = 0; i < 3; i++) {\n");
    vsy_TextFunTextColor(tf, red);
    vsy_TextFunString(tf, "   j += i;\n");
    vsy_TextFunTextColor(tf, blk);
    vsy_TextFunString(tf, "}\n");
    vsy_TextFunSetMode(tf, SYS_TEXT_PREFORMATTED, SYS_OFF);

    /* close files */
    vsy_TextFunCloseFile(tf);

    /* delete objects */
    vsy_HTMLTextEnd(htmltext);
    vsy_PlainTextEnd(plaintext);
    vsy_LaTeXTextEnd(latextext);
    vsy_TextTeeEnd(texttee);
    vsy_TextFunEnd(tf0);
    vsy_TextFunEnd(tf1);
    vsy_TextFunEnd(tf2);
    vsy_TextFunEnd(tf);
    return 0;
}
