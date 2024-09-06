add_rules("mode.debug", "mode.release")

-- 添加依赖库
add_requires("nlohmann_json", "cpr")

target("web_fetcher")
    set_kind("binary")
    set_languages("c++17")
    add_files("src/main.cpp")
    add_packages("nlohmann_json", "cpr")