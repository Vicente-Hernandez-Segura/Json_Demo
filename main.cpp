#include <stdio.h>
#include <iostream>
#include "chilkat/include/CkGlobalW.h"
#include "chilkat/include/CkHttpW.h"
#include "chilkat/include/CkJsonObjectW.h"
#include "chilkat/include/CkStringBuilderW.h"

void ChilkatSample();
void JsonSample();

int main(int argc, char *argv[]) {
    std::cout << "Json DEMO\n" << std::endl;
    ChilkatSample();
    JsonSample();

    return 0;
}

void ChilkatSample(void) {
    CkGlobalW glob;
    bool success = glob.UnlockBundle(L"Anything for 30-day trial");
    if (success != true) {
        wprintf(L"%s\n", glob.lastErrorText());
        return;
    }
    wprintf(L"%s\n", glob.lastErrorText());
}

void JsonSample(void) {
    // This example assumes the Chilkat API to have been previously unlocked.
    // See Global Unlock Sample for sample code.

    bool success;
    CkHttpW http;

    // Get the JSON we'll be parsing..
    const wchar_t *jsonStr =
            http.quickGetStr
                    (L"http://api.openweathermap.org/data/2.5/weather?q=Santiago,cl&units=metric&appid=b743bf9f4072917a4bc47462edaeffea");
    if (http.get_LastMethodSuccess() != true) {
        wprintf(L"Error!\n");
        return;
    }

    CkJsonObjectW json;
    json.Load(jsonStr);
    CkStringBuilderW sbText;

    sbText.Prepend(json.stringOf(L"weather[0].description"));
    sbText.Prepend(L"Sky: ");
    sbText.Prepend(L" \n");
    sbText.Prepend(json.stringOf(L"main.humidity"));
    sbText.Prepend(L"Humidity: ");
    sbText.Prepend(L" \n");
    sbText.Prepend(json.stringOf(L"main.pressure"));
    sbText.Prepend(L"Pressure: ");
    sbText.Prepend(L" \n");
    sbText.Prepend(json.stringOf(L"main.temp"));
    sbText.Prepend(L"Current Temp: ");
    sbText.Prepend(L" \n");
    sbText.Prepend(json.stringOf(L"sys.country"));
    sbText.Prepend(L"Country: ");
    sbText.Prepend(L" \n");
    sbText.Prepend(json.stringOf(L"name"));
    sbText.Prepend(L"City: ");
    sbText.Prepend(L" \n");

    std::wcout << sbText.asString();

}