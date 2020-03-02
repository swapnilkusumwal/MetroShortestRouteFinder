#include <bits/stdc++.h>
#define vertices 206

using namespace std;
vector<float> dist;
map<string,int> arr;

int k=0;

vector<vector<int> > all;

vector<int> switchesArr;

//vector<float> fares;

float distArr[5]={1.2,1.3,1.0,1.5,1.1};

float timeArr[10]={2.2,2.0,1.9,2.5,2.1,1.6,2.3,1.8,2.4,1.7};

string line[]={"b","b","b","b","b","b","b","b",/*yamunabank*/"b","b","bv",/*mandihouse*/
"b","by",/*rajivchowk*/"b","b","b","b","b","b","bg",/*kirtinagar*/"b","b","bp",/*rajourigarden*/"b",
"b","b","b","bm",/*janakpuriwest*/"b","b","b","b","b","b","b","b","b","b","b","b",
"bo",/*dwarkasector21*/"b","b","bm",/*botanicalgarden*/"b","b","b","b","b","b","b",
/*akshardham blue line ends here*/"v","v","v","v","vry",/*kashmeregate*/"v","vy"
/*centralsecretariate*/,"v","v","v","vp",/*lajpatnagar*/"v","v","v","vm",/*kalkajimandir*/
"v","v","v","v","v","v","v","v","v","v","v","v","v","v","v","v",/*violet line ends here*/
"yo"/*newdelhi*/,"y","y","y","y","y","y","y","yp",/*azadpur*/"y","y","y","y","y","y","y",
"y","y","yp"/*ina*/,"y","y","ym",/*hauzkhas*/"y","y","y","y","y","y","y","y","yd",
/*sikanderpur*/"y","y","y",/*yellow line ends here*/"m","m","m","m","m","m","m","m",
"m","m","m","m","m","m","m","m","m","m","m","m","m",/*magenta line ends*/"r",
"r","r","r","r","r","r","r","r","r","r","rg",/*inderlok*/"r","r","rp",/*netajisubhashplace*/
"r","r","r","r","r",/*red line ends here*/"g","g","g","g","g","g",
"g","g","g","g","g","g","g","g","g","g","g","g","g","g","g",/*green line ends here*/
"p","p","p","p","p","p","p","p","p","p","p","p","p"/*pink line ends here 190 index*/
,"d","d","d","d","d","d","d","d","d","d","d","o","o","o","o"
};
string arr1[]={"vaishali","kaushambi","anand vihar","karkarduma",
    "preet vihar","nirman vihar","laxmi nagar","yamuna bank","indraprastha",
    "pragati maidan","mandi house","barakhamba road","rajiv chowk",
    "ramakrishna ashram marg","jhande wale","karol bagh","rajendra place",
    "patel nagar","shadipur","kirti nagar","moti nagar","ramesh nagar",
    "rajouri garden","tagore garden","subash nagar","tilak nagar",
    "janakpuri east","janakpuri west","uttam nagar east","uttam nagar west",
    "navada","dwarka mor","dwarka","dwarka sector 14","dwarka sector 13"
    ,"dwarka sector 12","dwarka sector 11","dwarka sector 10","dwarka sector 9"
    ,"dwarka sector 8","dwarka sector 21","noida city centre",
    "golf course","botanical garden","noida sector 18","noida sector 16",
    "noida sector 15","new ashok nagar","mayur vihar extn.","mayur vihar 1",
    "akshardham","ito","delhi gate","jama masjid","lal quilla",
    "kashmere gate","janpath","central secretariate","khan market",
    "jln stadium","jangpura","lajpat nagar","moolchand","kailash colony",
    "nehru place","kalkaji mandir","govind puri","okhla","jasola-apollo",
    "sarita vihar","mohan estate","tughlakabad","badalpur","sarai","nhpc chowk",
    "mewala maharajpur","sector 28","badkal mor","faridabad old","ajronda",
    "bata chowk","escorts mujesar","new delhi","chawri bazar",
    "chandni chowk","civil lines","vidhansabha","vishwavidhyalaya",
    "gtb nagar","model town","azadpur","adarsh nagar",
    "jahangirpuri","haiderpur badli mor","rohini sector-18","samaypur badli"
    ,"patel chowk","udyog bhawan","lok kalyan marg","jorbagh","ina",
    "aiims","green park","hauz khas","malvia nagar","saket","qutab minar",
    "chhattarpur","sultanpur","ghitorni","arjan garh","gurudronacharya",
    "sikanderpur","mg road","iffco chowk","huda city centre"
    ,"okhla bird sanctuary","kalindi kunj","jasola vihar shaheen bagh",
    "okhla vihar","jamia millia islamia","sukhdev vihar","nsic okhla",
    "nehru enclave","greater kailash","chirag delhi","panchsheel park",
    "i.i.t","r.a.puram","munirka","vasant vihar","shankar vihar",
    "terminal 1-igi airport","sadar bazar cantonment","palam",
    "dasthrath puri","dabri mor","dilshad garden",
    "jhilmil","mansarover park","shahdara","welcome","seelampur",
    "shastri park","tis hazari","pul bangash","pratap nagar",
    "shastri nagar","inderlok","kanhaiya nagar","keshav puram",
    "netaji subash place","kohat enclave","pitampura","rohini east"
    ,"rohini west","rithala","city park","bus stand",
    "modern industrial estate","tikri border","tikri kalan",
    "ghevra metro station","mundka industrial area","mundka",
    "rajdhani park","nangloi railway station","nangloi",
    "surajmal stadium","udyog nagar","peeragarhi","paschim vihar west",
    "paschim vihar east","madipur","shivaji park","punjabi bagh",
    "ashok park main","satguru ram singh marg","majlis park",
    "shalimar bagh","shakurpur","punjabi bagh west","esi hospital",
    "mayapuri","naraina vihar","delhi cantt.","durgabai deshmukh south campus",
    "sir vishweshwaraiah moti bagh","bhikaji cama place",
    "sarojini nagar","south extension","sector 55-56",
    "sector 54 chowk","sector 53-54","sector 42-43","phase-1",
    "sikanderpur(rmgl)","phase 2","phase 3","moulsari avenue",
    "cyber city","belvedere towers","shivaji stadium",
    "dhaula kuan","delhi aerocity","igi airport"};



// 7 - yamuna bank
// 10 - mandi house
// 12 - rajiv chowk
// 19 - kirti nagar
// 22 - rajoli garden
// 27 - janakpuri west
// 65 - kalkaji mandir

class station
{
    int V;
    list<int> *adj;
public:
    station(int v)
    {
        V=v;
        adj = new list<int>[V];
    }


    void add_edge(int source, int dest)
    {
        adj[source].push_back(dest);
        adj[dest].push_back(source);
    }
/*
    bool BFS(int source, int dest, int v,int prev[], int dist[])
    {

        queue<int> queue1;

        bool visited[v];

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            dist[i] = INT_MAX;
            prev[i] = -1;
        }

        visited[source] = true;
        dist[source] = 0;

        queue1.push(source);

        list<int>::iterator i;

        while (!queue1.empty())
        {
            int u = queue1.front();
            queue1.pop();

            for (i = adj[u].begin(); i!=adj[u].end(); i++)
            {
                if (visited[*i] == false)
                {
                    visited[*i] = true;

                    dist[*i] = dist[u] + 1;

                    prev[*i] = u;
                    queue1.push(*i);

                    if (*i == dest)
                        return true;
                }
            }
        }

        return false;
    }
/*
    void printShortestRoute(int source,int dest, int v)
    {
        int prev[v], dist[v];

        if (BFS(source, dest, v, prev, dist) == false)
        {
            cout << "Given source and destination"
            << " are not connected";
            return;
        }

        vector<int> path;
        int reach = dest;
        path.push_back(reach);
        while (prev[reach] != -1) {
            path.push_back(prev[reach]);
            reach = prev[reach];
        }

        cout << "Shortest path length is : "
        << dist[dest];

        cout << "\nPath is::\n";
        for (int i = path.size() - 1; i >= 1; i--)
        {
            transform(arr1[path[i]].begin(),arr1[path[i]].end(),arr1[path[i]].begin(),
                      ::toupper);
            cout << arr1[path[i]] << " -> ";
        }
        transform(arr1[path[0]].begin(),arr1[path[0]].end(),arr1[path[0]].begin(),
                  ::toupper);
        cout<<arr1[path[0]]<<endl;
    }
*/
    void AllPaths(int s, int d)
    {
        bool *visited = new bool[V];

        // array to store paths
        int *path = new int[V];
        int path_index = 0; // Initialize path[] as empty

        // all vertices are not visited initially

        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the function to store all paths
        storeAllPaths(s, d, visited, path, path_index);
    }

// A recursive function to print all paths from source(u) to destination(d).
// using DFS
    void storeAllPaths(int u, int d, bool visited[],
                              int path[], int &path_index)
    {
        //current station is marked true
        visited[u] = true;
        path[path_index] = u;
        path_index++;

        // if current station(u) is same as d,
        // then store the route
        if (u == d)
        {
            vector<int> abc;
            for (int i = 0; i<path_index; i++)
                abc.push_back(path[i]);
                //cout << endl;
            all.push_back(abc);
        }
        else
        {
            // all the vertices adjacent to current vertex
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (!visited[*i])
                    storeAllPaths(*i, d, visited, path, path_index);
        }

    // Remove current vertex from path[] and mark it as unvisited by reducing the last index
        path_index--;
        visited[u] = false;
    }
    void add()
    {
        //vaishali to jankapuri west
        for(int i=0;i<40;i++)
        {
            add_edge(i,i+1);
        }

        //ncc to akshardham
        for(int i=41;i<50;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(50,7);//to yamuna bank

        //purple up
        for(int i=51;i<55;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(10,51);//mandi to barakhamba

        //purple down
        for(int i=56;i<81;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(10,56);//madi house to janpath
        add_edge(12,82);//rajiv chowk to new delhi
        add_edge(82,83);//ndls to chawri
        add_edge(83,84);//chawri chandni
        add_edge(84,55);//chandni to kashmere
        add_edge(55,85);//kasmere to civil

        //yellow up from civil to samaypur
        for(int i=85;i<95;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(12,96);//rajiv to patel chowk
        add_edge(96,57);//pate to central sec
        add_edge(57,97);//central udyog

        //yellow down
        for(int i=97;i<115;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(43,116);//botanical to okhla

        //majenta start to purple
        for(int i=116;i<122;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(122,65);//nsic okhla to kalkaji mandir
        add_edge(65,123);//kalkaji to nehru place

        //majenta mid to yellow
        for(int i=123;i<126;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(126,103);//panchsheel to hauz khas
        add_edge(103,127);//hauz khas to iit

        //iit to dabri mor(majenta end)
        for(int i=127;i<136;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(136,27);//dabri mor to janakpuri west

        //dilshad to shastri(red start)
        for(int i=137;i<143;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(143,55);//shastri to kashmere
        add_edge(55,144);//kashmere to tis

        //red from tis to rithala
        for(int i=144;i<156;i++)
        {
            add_edge(i,i+1);
        }

        //green end
        for(int i=157;i<177;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(148,176);//inderlok to ashok
        add_edge(19,177);//kirti nagar to satguru
        add_edge(178,90);//majlish to azadpur
        add_edge(90,179);//azadpur to shalimar
        add_edge(179,151);//shalimar to netaji subash place
        add_edge(151,180);//netaji to shakurpur
        add_edge(180,181);//shakurpur to madhipur
        add_edge(181,182);//madhipur to esi hosp
        add_edge(182,22);//esi hosp to rajouri
        add_edge(22,183);//rajouri to mayapuri

        //pink from mayapuri to sarojini
        for(int i=183;i<189;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(189,100);//sarojini to ina
        add_edge(100,190);//ina to south extn
        add_edge(61,190);//south extn to lajpat

        //rapid metro start
        for(int i=191;i<195;i++)
        {
            add_edge(i,i+1);
        }

        add_edge(195,112);//phase-1 to sikanderpur
        add_edge(112,196);//sikanderpur to sikanderpur rmgl

        //sikanderpur rmgl to belvedere
        for (int i = 196; i < 201; ++i)
        {
            add_edge(i,i+1);
        }

        add_edge(201,197);//belvedere to phase 2

        //airport line
        for (int i = 202; i < 205; ++i)
        {
            add_edge(i,i+1);
        }

        add_edge(202,82);//new delhi to shivaji stadium
        add_edge(205,40);//igi airport to dwarka sector 21


    }

    int countAero(vector<int> a)
    {
        int c=0;

        for(int i=0;i<a.size();i++)
        {
            if(line[a[i]]=="o")
                c++;
        }
        return c;
    }

    float calcTime(int stations,int c)
    {
        float sum=0;

        for(int i=0;i<stations;i++)
        {
            sum+=timeArr[rand()%10];
        }

        sum+=(c*4);

        return sum;
    }

    float calcDist(int stations,int c)
    {
        float sum=0;

        for(int i=0;i<stations;i++)
        {
            sum+=distArr[rand()%5];
        }

        sum+=(c*2);

        return sum;
    }

    int fareCalc(int stations,int switches,vector<int> a)
    {
        int fare;

        fare=(stations/5)*10;

        if(fare>=50 && switches==0)
            fare=50;

        else if(fare>=50 && switches>0)
            fare=60;

        int c=0;

        for(int i=0;i<a.size();i++)
        {
            if(line[a[i]]=="o")
                c++;
        }

        fare-=(c*5);

        fare+=(c*20);

        if(fare>100)
            fare=100;

        if(stations <=5)
            return 10;

        return fare;
    }

    void switchesCount(vector <int> index)
    {
        int j=0;
        for(int i=0;i<all.size();i++)
        {
        int switches=0;
        //int xx=0;
        //bool yy=0;
        int t=index[i];
        //cout<<"********************************************************************************"<<endl<<endl;
        for(;j<all[t].size()-1;j++)
        {

            if(j<all[t].size()-2){
            if(line[all.at(t)[j]]!=line[all.at(t)[j+2]])
                if(line[all.at(t)[j+2]].length()==1 && line[all.at(t)[j]].length()==1)
                {
                    switches++;
                    //xx=0;
                    //yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="laxmi nagar" && arr1[all.at(t)[j]]=="akshardham" && arr1[all.at(t)[j+1]]=="yamuna bank" )
                {
                    switches++;
                    //xx=0;
                    //yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="akshardham" && arr1[all.at(t)[j]]=="laxmi nagar" && arr1[all.at(t)[j+1]]=="yamuna bank" )
                {
                    switches++;
                 //   xx=0;
                   // yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="shivaji stadium" && arr1[all.at(t)[j+1]]=="new delhi" && arr1[all.at(t)[j]]=="rajiv chowk")
                {
                    switches++;
                 //   xx=0;
                   // yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="new delhi" && arr1[all.at(t)[j+1]]=="rajiv chowk" && arr1[all.at(t)[j]]=="barakhamba road")
                {
                    //cout
                    switches++;
                  //  xx=0;
                    //yy=1;
                }
                if(arr1[all.at(t)[j]]=="ramakrishna ashram marg" && arr1[all.at(t)[j+1]]=="rajiv chowk" && arr1[all.at(t)[j+2]]=="new delhi")
                {
                    switches++;
                    //xx=0;
                  //  yy=1;
                }

            }
           // if(yy)
             //   xx++;
          /*          if(j>0)
            if(yy && xx==2 || (arr1[all.at(t)[j]]=="new delhi" && arr1[all.at(t)[j+1]]=="shivaji stadium") || (arr1[all.at(t)[j-1]]=="barakhamba road" &&
                                                                    arr1[all.at(t)[j]]=="rajiv chowk" && arr1[all.at(t)[j+1]]=="new delhi") || (arr1[all.at(t)[j-1]]=="barakhamba road" &&
                                                                    arr1[all.at(t)[j]]=="rajiv chowk" && arr1[all.at(t)[j+1]]=="new delhi"))
            {
                cout<<" (change here) ";
                xx=0;
                yy=0;
            }

            cout<<arr1[all.at(t)[j]]<<" -> ";

        }
        */
        }
        switchesArr.push_back(switches);
       // cout<<arr1[all.at(t)[j]]<<endl<<endl;
        //cout<<"Number of Stations : "<< stations<<endl<<endl;
        //cout<<"Number of Switches : "<<switches<<endl<<endl;
        //cout<<"FARE : " << fareCalc(stations,switches,all[t])<<endl<<endl;
        //cout<<"DISTANCE : "<<calcDist();
       // cout<<"********************************************************************************"<<endl<<endl;
        switches=0;
        j=0;
        }
    }

    void route(vector<int>index)
    {
        int j=0;

        for(int i=0;i<3 && i<all.size();i++)
        {

        int switches1=0;
        int xx=0;
        bool yy=0;
        int t=index[i];

        cout<<"********************************************************************************"<<endl<<endl;
        for(;j<all[t].size()-1;j++)
        {

            if(j<all[t].size()-2){
            if(line[all.at(t)[j]]!=line[all.at(t)[j+2]])
                if(line[all.at(t)[j+2]].length()==1 && line[all.at(t)[j]].length()==1)
                {
                    switches1++;
                    xx=0;
                    yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="laxmi nagar" && arr1[all.at(t)[j]]=="akshardham" && arr1[all.at(t)[j+1]]=="yamuna bank" )
                {
                    switches1++;
                    xx=0;
                    yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="akshardham" && arr1[all.at(t)[j]]=="laxmi nagar" && arr1[all.at(t)[j+1]]=="yamuna bank" )
                {
                    switches1++;
                    xx=0;
                    yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="shivaji stadium" && arr1[all.at(t)[j+1]]=="new delhi" && arr1[all.at(t)[j]]=="rajiv chowk")
                {
                    switches1++;
                    xx=0;
                    yy=1;
                }
                if(arr1[all.at(t)[j+2]]=="new delhi" && arr1[all.at(t)[j+1]]=="rajiv chowk" && arr1[all.at(t)[j]]=="barakhamba road")
                {
                    //cout
                    switches1++;
                    xx=0;
                    yy=1;
                }
                if(arr1[all.at(t)[j]]=="ramakrishna ashram marg" && arr1[all.at(t)[j+1]]=="rajiv chowk" && arr1[all.at(t)[j+2]]=="new delhi")
                {
                    switches1++;
                    xx=0;
                    yy=1;
                }

            }
            if(yy)
                xx++;
            if(j>0)
            if(yy && xx==2 || (arr1[all.at(t)[j]]=="new delhi" && arr1[all.at(t)[j+1]]=="shivaji stadium") || (arr1[all.at(t)[j-1]]=="barakhamba road" &&
                                arr1[all.at(t)[j]]=="rajiv chowk" && arr1[all.at(t)[j+1]]=="new delhi") || (arr1[all.at(t)[j-1]]=="barakhamba road" &&
                                                                    arr1[all.at(t)[j]]=="rajiv chowk" && arr1[all.at(t)[j+1]]=="new delhi"))
            {
                cout<<" (change here) ";
                xx=0;
                yy=0;
            }

            cout<<arr1[all.at(t)[j]]<<" -> ";
        }

        int co=countAero(all[t]);
        int stations=all[t].size()-1;

        cout<<arr1[all.at(t)[j]]<<endl<<endl<<endl;

        cout<<"Number Of Stations : "<< stations<<endl<<endl;

        cout<<"Number Of Switches : "<<switches1<<endl<<endl;

        cout<<"Fare : " << "Rs."<<fareCalc(stations,switches1,all[t])<<endl<<endl;

        cout<<"Total Distance : "<<calcDist(stations,co)<<" KM"<<endl<<endl;

        cout<<"Time Taken : "<<(int)ceil(calcTime(stations,co))<<" " <<"min"<<endl<<endl;
        //cout<<"DISTANCE : "<<calcDist();
        cout<<"********************************************************************************"<<endl<<endl;
        switches1=0;
        j=0;
        }
    }
    void minSwitches(vector<int>len,vector<int> index)
    {
        for(int i=0;i<all.size();i++)
        {
            for(int j=0;j<all.size()-1;j++)
            {
                if(switchesArr[j] > switchesArr[j+1])
                {
                    int t1=len[j];
                    len[j]=len[j+1];
                    len[j+1]=t1;


                    int t2=index[j];
                    index[j]=index[j+1];
                    index[j+1]=t2;


                    int s1=switchesArr[j];
                    switchesArr[j]=switchesArr[j+1];
                    switchesArr[j+1]=s1;
                }
            }
        }
        for(int i=0;i<all.size();i++)
        {
            for(int j=0;j<all.size()-1;j++)
            {
                if(len[j] > len[j+1]  && switchesArr[j]==switchesArr[j+1])
                {
                    int t1=len[j];
                    len[j]=len[j+1];
                    len[j+1]=t1;


                    int t2=index[j];
                    index[j]=index[j+1];
                    index[j+1]=t2;


                    int s1=switchesArr[j];
                    switchesArr[j]=switchesArr[j+1];
                    switchesArr[j+1]=s1;
                }
            }
        }
        route(index);
    }
    void minStations(vector<int>len,vector<int>index)
    {
        for(int i=0;i<all.size();i++)
        {
            for(int j=0;j<all.size()-1;j++)
            {
                if(len[j]>len[j+1])
                {
                    int t1=len[j];
                    len[j]=len[j+1];
                    len[j+1]=t1;


                    int t2=index[j];
                    index[j]=index[j+1];
                    index[j+1]=t2;


                    int s1=switchesArr[j];
                    switchesArr[j]=switchesArr[j+1];
                    switchesArr[j+1]=s1;
                }
            }
        }
        for(int i=0;i<all.size();i++)
        {
            for(int j=0;j<all.size()-1;j++)
            {
                if(switchesArr[j] > switchesArr[j+1] && len[j]==len[j+1])
                {
                    int t1=len[j];
                    len[j]=len[j+1];
                    len[j+1]=t1;


                    int t2=index[j];
                    index[j]=index[j+1];
                    index[j+1]=t2;


                    int s1=switchesArr[j];
                    switchesArr[j]=switchesArr[j+1];
                    switchesArr[j+1]=s1;
                }
            }
        }

        route(index);
    }
    /*
    void minFare(vector<int>len,vector<int>index)
    {
        
    }
    */

};
void def()
{
    for(int i=0;i<vertices;i++)
    {
        arr.insert(pair<string,int>(arr1[i],i));
    }
}
int main()
{
    def();

    station delhi(vertices);

    delhi.add();

    cout<<endl<<endl;


    cout<<"DISCLAIMER: The travel time , fare and distance shown below is \n"
    <<"            indicative based on used algorithm . The actual time \n"
    <<"            taken for travel , fare and distance may vary \n"
    <<"            considering the algorithm used by DMRC ."<<endl<<endl<<endl;


    s1:

    cout<<"Enter Source Station: ";

    string source;

    getline (cin ,source);

    transform(source.begin(), source.end(), source.begin(), ::tolower);
    cout<<endl;

    cout<<"Enter Destination: ";

    string dest;
    getline (cin , dest);

    bool c1=0,c2=0;

    for(int i=0;i<vertices;i++)
    {
        if(source==arr1[i])
            c1=1;
        if(dest==arr1[i])
            c2=1;
    }
    if(!c1 && !c2)
    {
        cout<<"Source And Destination Does Not Exist "<<endl<<endl;
        return 0;
    }
    else if(!c1 && c2)
    {
        cout<<"Source Does Not Exist"<<endl<<endl;
        return 0;
    }
    else if(c1 && !c2)
    {
        cout<<"Destination Does Not Exist"<<endl<<endl;
        return 0;
    }

    transform(dest.begin(), dest.end(), dest.begin(), ::tolower);

    //delhi.printShortestRoute(arr[source], arr[dest], vertices);

    delhi.AllPaths(arr[source],arr[dest]);

    map<int,int> shortestPaths;
    cout<<endl;

    vector<int> index;
    vector<int> len;

    for(int i=0;i<all.size();i++)
        index.push_back(i);


    for(int j=0;j<all.size();j++)
        len.push_back(all[j].size());

    delhi.switchesCount(index);

    int choice;

    cout<<"Press 1 for shortest route with minimum number of switches \n"<<endl
    <<"Press any key for minimum number of stations\n"<<endl;
    cin>>choice;
    cout<<endl<<endl;
    switch(choice)
    {
        case 1:
            delhi.minSwitches(len,index);
        break;
        default:
            delhi.minStations(len,index);
            break;
           // delhi.minFare(len,index);
    }

    return 0;
}

