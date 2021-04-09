#include "driver.hh"
#include "parser.hh"

#include "visitors/printvisitor.h"
#include "visitors/interpreter.h"
#include "visitors/symboltreevisitor.h"
#include "helpers/VariantProcessor.h"

Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();

    std::cout << "Compile OK\n";

    PrintVisitor v("output.txt");
    v.Visit(program);
    std::cout << "PrintVisitor OK\n";

    SymbolTreeVisitor STV;
    STV.Visit(program);

    Interpreter interpret;
    auto calculated_map = interpret.GetResult(program);
    std::cout << "Interpreter OK\n\n";
    std::cout << "Variables values: \n";
    for (auto const&[name, value] : calculated_map) {
        std::cout << name << " ";
        VariantProcessor::PrintValue(value);
    }

    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
    stream.close();
}

