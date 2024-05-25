#include <iostream>
#include <jsoncpp/json/json.h>
#include <libjsonnet++.h>
bool ReadConfigFromJson(const std::string &path) {
  jsonnet::Jsonnet jsonnet;
  jsonnet.init();
  std::string full_config_json_str;
  jsonnet.bindExtVar("b", "4");
  if (!jsonnet.evaluateFile(path, &full_config_json_str)) {
    std::cout << "Parsing config " << path << " failed.";
    return false;
  }

  std::cout << "Parsing config: \n" << full_config_json_str << std::endl;
  return true;
}

int main() {
  bool status = ReadConfigFromJson("./main.jsonnet");
  return 0;
}