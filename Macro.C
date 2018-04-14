//Import the histogramme hAllSkyCoarse_sigma;1

{
TFile DATA("C:\\root_v5.34.36\\DATA.root");
TH2D *histo = DATA.Get("hAllSkyCoarse_sigma;1");
histo->Draw("colz");

cout << "opened histo with nbins " << histo->GetNbinsX() << endl;
//Searching the maximum bins on x and y axes
double nbinx = histo -> GetNbinsX();
double nbiny = histo -> GetNbinsY();
//fstream  fout
//Searching the index where the content of the bins respect the condition
for (int i = 0; i < nbinx; i++)
{
  for (int j = 0; j < nbiny; j++)
  {
    Float_t content = histo->GetBinContent(i,j);
    //content is the date of the event in julien day and the condition is
    //that content<log(2 seconds in Julien days)

    if(content < TMath::Log10(2./24./60./60.)){
      double  x = histo->GetXaxis()->GetBinCenter(i);
      double y = histo->GetYaxis()->GetBinCenter(j);
      cout<< "Position of this content: "<< content << "\t" << i << j << x << y;
    }
  }
}
}
