#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

int main() {
    //读取config.json文件
    std::ifstream config_file("..\\..\\..\\..\\config.json");
    //硬件部_刘苏昊\build\windows\x64\release\web_fetcher.exe
    if (!config_file.is_open()) {
        std::cerr << "无法打开config.json文件" << std::endl;
        return 1;
    }

    nlohmann::json config;
    config_file >> config;
    std::string url = config["url"];
    //std::string url = "http://baidu.com";
    cpr::Response r = cpr::Get(cpr::Url{url});
    if (r.status_code != 200) {
        std::cerr << "无法访问网址: " << url << std::endl;
        return 1;
    }

    // 将网页内容保存到文件
    std::ofstream output_file("..\\..\\..\\..\\output.html");
    if (!output_file.is_open()) {
        std::cerr << "无法创建output.html文件" << std::endl;
        return 1;
    }
    output_file << r.text;

    std::cout << "网页内容已保存到output.html" << std::endl;
    return 0;
}