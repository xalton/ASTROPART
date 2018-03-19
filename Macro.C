//Import of the histogramme hAllSkyCoarse_sigma;1
#include <TH2.h>
void Macro(){
TH2D *histo = DATA.Get("hAllSkyCoarse_sigma;1")
//Searching of maximum bins on x and y axes
double nbinx = histo -> GetNbinsX()
double nbiny = histo -> GetNbinsy()
//Searching the index where the content of the bins respect the condition
for (int i = 0, i < nbinx, i++){
  for (int j = 0, j < nbiny, j++){
    Float_t content = histo -> GetBincontent(i,j)
    //content is the date of the event in julien day and the condition is
    //that content<log(2 seconds in Julien days)
    if(content < -7.198073971421246 ){
      x = histo -> GetXaxis() -> GetBincenter();
      y = histo -> GetYaxis() -> GetBincenter();
      cout<< "Position of this content:"<< content << i << j << x << y;
    }
  }
}
}
