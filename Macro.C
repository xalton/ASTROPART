
{
  ofstream fichier("BHNdetection.txt", ios::out | ios::trunc);
  //If it's open
  if(fichier)
   {
     //Import histograms
     TFile DATA("C:\\root_v5.34.36\\DATA.root");
     TH2D *histo = DATA.Get("hAllSkyCoarse_sigma;1");
     TH2D *histons = DATA.Get("hAllSkyCoarse_ns;1");
     TH2D *histogamma = DATA.Get("hAllSkyCoarse_gamma;1");
     TH2D *histomean = DATA.Get("hAllSkyCoarse_mean;1");
     //histo->Draw("colz");
     //cout << "opened histo with nbins " << histo->GetNbinsX() << endl;
     //Searching the maximum bins on x and y axes
     double nbinx = histo -> GetNbinsX();
     double nbiny = histo -> GetNbinsY();
     //Searching the index where the content of the bins respect the condition
     for (int i = 0; i < nbinx; i++)
     {
       for (int j = 0; j < nbiny; j++)
       {
         Float_t content = histo->GetBinContent(i,j);
         Float_t ns = histons->GetBinContent(i,j);
         Float_t gamma = histogamma->GetBinContent(i,j);
         Float_t mean = histomean->GetBinContent(i,j);

         //content is the date of the event in julien day and the condition is
         //that content<log(2,3,4 and 5 seconds in Julien days)
          if(content < TMath::Log10(2./24./60./60.))
          {
            double  x = histo->GetXaxis()->GetBinCenter(i);
            double  y = histo->GetYaxis()->GetBinCenter(j);
            fichier <<  "content: "<< content << "\t" << "index i: "<< i <<  "\t"
            <<"index j: "<< j <<  "\t" <<"ascension: "<< x <<  "\t" <<"declination =  "<< y <<"\t" <<"ns:"<< ns <<"\t"<<"gamma: "<< gamma <<
           "\t"<<"Mean : "<< "\t"<< mean<< endl;
          }
          fichier <<"   "<<"/n";
          //if(TMath::Log10(2./24./60./60.) <content < TMath::Log10(3./24./60./60.))
         {
           double  x = histo->GetXaxis()->GetBinCenter(i);
           double  y = histo->GetYaxis()->GetBinCenter(j);
           fichier <<  "content: "<< content << "\t" << "index i: "<< i <<  "\t"
           <<"index j: "<< j <<  "\t" <<"ascension: "<< x <<  "\t" <<"declination =  "<< y <<"\t" <<"ns:"<< ns <<"\t"<<"gamma: "<< gamma <<
           "\t"<<"Mean : "<< "\t"<< mean<< endl;
         }
         //fichier <<"   "<<"/n";
         if(TMath::Log10(3./24./60./60.) < content < TMath::Log10(4./24./60./60.))
           {
             double  x4 = histo->GetXaxis()->GetBinCenter(i);
             double  y4 = histo->GetYaxis()->GetBinCenter(j);
             fichier <<  "content: "<< content << "\t" << "index i: "<< i <<  "\t"
             <<"index j: "<< j <<  "\t" <<"ascension: "<< x <<  "\t" <<"declination =  "<< y <<"\t" <<"ns:"<< ns <<"\t"<<"gamma: "<< gamma <<
             "\t"<<"Mean : "<< "\t"<< mean<< endl;
           }
         //fichier <<"   "<<"/n";
         if(TMath::Log10(4./24./60./60.) < content < TMath::Log10(5./24./60./60.))
           {
             double  x = histo->GetXaxis()->GetBinCenter(i);
             double  y = histo->GetYaxis()->GetBinCenter(j);
             fichier <<  "content: "<< content << "\t" << "index i: "<< i <<  "\t"
             <<"index j: "<< j <<  "\t" <<"ascension: "<< x <<  "\t" <<"declination =  "<< y <<"\t" <<"ns:"<< ns <<"\t"<<"gamma: "<< gamma <<
             "\t"<<"Mean : "<< "\t"<< mean<< endl;
           }
       }
     }
       }
       //we close the file
       fichier.close();
       cout<<"End of writing"<<std::endl;
   //if not
   else
   {
       std::cout <<"Error opening file "<<std::endl;
   }
}
