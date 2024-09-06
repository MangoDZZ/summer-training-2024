#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

int main() {
    //��ȡconfig.json�ļ�
    std::ifstream config_file("..\\..\\..\\..\\config.json");
    //Ӳ����_�����\build\windows\x64\release\web_fetcher.exe
    if (!config_file.is_open()) {
        std::cerr << "�޷���config.json�ļ�" << std::endl;
        return 1;
    }

    nlohmann::json config;
    config_file >> config;
    std::string url = config["url"];
    //std::string url = "http://baidu.com";
    cpr::Response r = cpr::Get(cpr::Url{url});
    if (r.status_code != 200) {
        std::cerr << "�޷�������ַ: " << url << std::endl;
        return 1;
    }

    // ����ҳ���ݱ��浽�ļ�
    std::ofstream output_file("..\\..\\..\\..\\output.html");
    if (!output_file.is_open()) {
        std::cerr << "�޷�����output.html�ļ�" << std::endl;
        return 1;
    }
    output_file << r.text;

    std::cout << "��ҳ�����ѱ��浽output.html" << std::endl;
    return 0;
}