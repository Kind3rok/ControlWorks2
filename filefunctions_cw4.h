#ifndef FILEFUNCTIONS_CW4_H
#define FILEFUNCTIONS_CW4_H

bool IsDataCorrectCW4(std::ifstream& file);
std::string CheckFileCW4();
void GetTextFromFile(std::string& text, std::string& path);
void SaveToFile(const std::string& restoredText, const std::string& modifiedText, int save_choice);

#endif