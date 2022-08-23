#include <stdio.h>

#include "expat.h"

#include <string>

static void XMLCALL
startElement(void *userData, const XML_Char * name, const XML_Char ** atts)
{
    XML_Parser parser = (XML_Parser)userData;
    int index = XML_GetCurrentByteIndex(parser);
    int bIsSingle = XML_CurrentNodeIsSigle(parser);
    int count = XML_CurrentNodeCount(parser);
    printf("element start tag: %s index:%d\n", name, index);
    int i;
    for (i = 0; atts[i]; ++i)
    {
        printf("element attr : %s\n", atts[i]);
    }
}

static void XMLCALL
endElement(void *userData, const XML_Char * name)
{
    XML_Parser parser = (XML_Parser)userData;
    int count = XML_CurrentNodeCount(parser);
    printf("element end tag: %s\n", name);
}

static void XMLCALL
textElement(void *userData, const XML_Char *s, int len)
{
    std::string text((char*)s, len);
    printf("element text: %s \n", text.c_str());
}

int main()
{
    // const char* text = "<doc>text</doc>";
    // const char* text = "<doc a = \"fd\" b = \"123\">text</doc>";
    // const char* text = "<doc a=fd>text</doc>";
    // const char* text = "<doc a=fd><tt b=123>hello</tt></doc>";
    // const char* text = "<doc a=f测试d/>";
    const char* text = "<doc a=fd> <doc1 h=ww/><tt b=123>hello</tt></doc>";
    XML_Parser parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser, parser);
    XML_SetElementHandler(parser, startElement, endElement);
    XML_SetCharacterDataHandler(parser, textElement);
    XML_Parse(parser, text, strlen(text), 1);
    XML_ParserFree(parser);
    return 0;
}