#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

const std::string BGPLS = "/home/uid0001/pls/all.pls";

  std::vector<std::string> vlines4(std::string fn) {
    std::vector<std::string> res;
    std::ifstream ifile;
    std::string tmp;

    ifile.open(fn.c_str());
    while(ifile.good()) {
      std::getline(ifile, tmp);
      if (tmp.length())
	res.push_back(tmp);
    }
    ifile.close();

    return res;
  }

  void save2(std::string fname, std::vector<std::string> lines) {
    typedef std::vector<std::string>::iterator Line;
    std::ofstream ofile;
    ofile.open(fname.c_str());
    for(Line line = lines.begin(); line != lines.end(); ++line)
      ofile << *line << std::endl;
    ofile.close();
  }

  void mkbgpls() {
    unsigned int iRnd, oRnd;
    std::string tmp;
    std::vector<std::string> vpls;

    vpls = vlines4(BGPLS);

    srand ( time(NULL) );

    oRnd = 3;
    if (vpls.size() > 5)
      for (unsigned int i = 0; i < vpls.size(); i++) {
	iRnd = rand() % vpls.size();
	if (oRnd != iRnd) {
	  tmp = vpls[oRnd];
	  vpls[oRnd] = vpls[iRnd];
	  vpls[iRnd] = tmp;
	  oRnd = iRnd;
	}
      }

    save2(BGPLS, vpls);
  }

int main() {
  mkbgpls();
  return 0;
}
