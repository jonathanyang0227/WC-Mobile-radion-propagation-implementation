#include <bits/stdc++.h>

using namespace std;

int ramdom(double percent)
{
    double n = (double) rand() / (RAND_MAX + 1.0);
    // cout<<n<<endl;
    if (n < percent) {
        return 1;
    } else {
        return 0;
    }
}

int car_enter(double percent){        
    int arrival=0;
    for(int a=0;a<1000;a++){
        double n = (double) rand() / (RAND_MAX + 1.0000);    
        //cout<<n<<endl;
        if(n<=percent){
            arrival++;
        }
    }

    return arrival;
}

typedef struct car {
    vector<int> car_n;
    vector<int> direct;
    vector<int> x_point;                   
    vector<int> y_point;
    vector<int> p_best;
    vector<int> p_threshold;
    vector<int> p_entropy;
    vector<int> p_min;
    vector<int> p_my;
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;
    vector<int> p4;
} add;

int main(){
    add car;
    double pmin = 10;
    double b1x = 360;
    double b1y = 680;
    double b2x = 660;
    double b2y = 658;
    double b3x = 330;
    double b3y = 350;
    double b4x = 640;
    double b4y = 310;
    double p1, p2, p3, p4,powerb=0,powermin=0,powert=0,powere=0,powermy=0;
    int car_num = 0;
    int b_num=0,t_num=0,m_num=0,e_num=0,my_num=0;
    int direct_n ;
    int c_car_num=0;
    int j,k,a,total_car=0;
    int me=5,mt=20;
    int last_b_num=0,last_e_num=0,last_t_num=0,last_my_num=0;
    int c_b_num=0,c_e_num=0,c_t_num=0,c_my_num=0;
    int s=0;
    srand(time(NULL));
    double v[3] = {0.0005, 0.00033, 0.0002};
    fstream file_b, file_t, file_e ,file_my;
    file_b.open("best.txt",ios::out);
    file_t.open("threshold.txt",ios::out);
    file_e.open("entropy.txt",ios::out);
    file_my.open("my.txt",ios::out);
    double lamda = v[0];
    cout<<"lamda= "<<lamda<<endl;
         double arrival = (1 - exp((-lamda) * (1)));
         cout<<"arrival rate:   "<<arrival<<endl;
        //time
        for (int i = 0; i <2000 ; i++) {
            for(a=0;a<1000;a++){
            for(j=1;j<=9;j++){
            //each entry
                    if (ramdom(arrival)) {
                        c_car_num+=1;
                        car_num += 1;
                        car.car_n.push_back(car_num);
                        direct_n = (rand() % 5) + 1;  
                        car.x_point.push_back(j * 100);
                        car.y_point.push_back(0);
                        p1 = 100-33 -
                             (20 * log10(pow(pow(car.x_point.back() - b1x, 2) +
                                             pow(car.y_point.back() - b1y, 2),
                                         0.5)));
                        if(p1<pmin)
                            p1=0;
                        p2 = 100-33 -
                             (20 * log10(pow(pow(car.x_point.back() - b2x, 2) +
                                             pow(car.y_point.back() - b2y, 2),
                                         0.5)));
                        if(p2<pmin)
                            p2=0;
                        p3 = 100-33 -
                             (20 * log10(pow(pow(car.x_point.back() - b3x, 2) +
                                             pow(car.y_point.back() - b3y, 2),
                                         0.5)));
                        if(p3<pmin)
                            p3=0;
                        p4 = 100-33 -
                             (20 * log10(pow(pow(car.x_point.back() - b4x, 2) +
                                             pow(car.y_point.back() - b4y, 2),
                                         0.5)));
                        if(p4<pmin)
                            p4=0;
                        if (direct_n <= 3)
                            car.direct.push_back(2);  // up
                        else if (direct_n == 4)
                            car.direct.push_back(1);  // right
                        else if(direct_n==5)
                            car.direct.push_back(4);  // left

                        car.p1.push_back(p1);
                        car.p2.push_back(p2);
                        car.p3.push_back(p3);
                        car.p4.push_back(p4);
                        car.p_min.push_back(0);
                        car.p_best.push_back(0);
                        car.p_threshold.push_back(0);
                        car.p_entropy.push_back(0);
                        car.p_my.push_back(0);
                    }

                if (ramdom(arrival)) {
                    c_car_num+=1;
                    car_num += 1;
                    car.car_n.push_back(car_num);
                    direct_n = (rand() % 5) + 1;    
                    car.x_point.push_back(0);
                    car.y_point.push_back(j * 100);
                    p1 = 100-33-
                         (20 * log10(pow(pow(car.x_point.back() - b1x, 2) +
                                             pow(car.y_point.back() - b1y, 2),
                                         0.5)));
                    if(p1<pmin)
                        p1=0;
                    p2 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b2x, 2) +
                                             pow(car.y_point.back() - b2y, 2),
                                         0.5)));
                     if(p2<pmin)
                         p2=0;
                    p3 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b3x, 2) +
                                             pow(car.y_point.back() - b3y, 2),
                                         0.5)));
                        if(p3<pmin)
                            p3=0;
                    p4 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b4x, 2) +
                                             pow(car.y_point.back() - b4y, 2),
                                         0.5)));
                    if(p4<pmin)
                            p4=0;
                    if (direct_n <= 3)
                        car.direct.push_back(1);  //右
                    else if (direct_n == 4)
                        car.direct.push_back(2);  //上
                    else if(direct_n==5)
                        car.direct.push_back(3);  //下

                    car.p1.push_back(p1);
                    car.p2.push_back(p2);
                    car.p3.push_back(p3);
                    car.p4.push_back(p4);
                    car.p_min.push_back(0);                  
                    car.p_best.push_back(0);
                    car.p_threshold.push_back(0);
                    car.p_entropy.push_back(0);
                    car.p_my.push_back(0);
               }

                if (ramdom(arrival)) {
                    c_car_num+=1;
                    car_num += 1;
                    car.car_n.push_back(car_num);
                    direct_n = (rand() % 5) + 1;    
                    car.x_point.push_back(j * 100);
                    car.y_point.push_back(1000);
                    p1 = 100-33-
                         (20 * log10(pow(pow(car.x_point.back() - b1x, 2) +
                                             pow(car.y_point.back() - b1y, 2),
                                         0.5)));
                    if(p1<pmin)
                        p1=0;
                    p2 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b2x, 2) +
                                             pow(car.y_point.back() - b2y, 2),
                                         0.5)));
                     if(p2<pmin)
                         p2=0;
                    p3 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b3x, 2) +
                                             pow(car.y_point.back() - b3y, 2),
                                         0.5)));
                        if(p3<pmin)
                            p3=0;
                    p4 =100- 33 -
                         (20 * log10(pow(pow(car.x_point.back() - b4x, 2) +
                                             pow(car.y_point.back() - b4y, 2),
                                         0.5)));
                    if(p4<pmin)
                            p4=0;
                    if (direct_n <= 3)
                        car.direct.push_back(3);  // down
                    else if (direct_n == 4)
                        car.direct.push_back(4);  // left
                    else if (direct_n==5)
                        car.direct.push_back(1);  // right

                    car.p1.push_back(p1);
                    car.p2.push_back(p2);
                    car.p3.push_back(p3);
                    car.p4.push_back(p4);
                    car.p_min.push_back(0);                    
                    car.p_best.push_back(0);
                    car.p_threshold.push_back(0);
                    car.p_entropy.push_back(0);
                    car.p_my.push_back(0);
                }

                if (ramdom(arrival)) {
                    c_car_num+=1;
                    car_num += 1;
                    car.car_n.push_back(car_num);
                    direct_n = (rand() % 5) + 1;    
                    car.x_point.push_back(1000);
                    car.y_point.push_back(j * 100);
                    p1 = 100-33-
                         (20 * log10(pow(pow(car.x_point.back() - b1x, 2) +
                                             pow(car.y_point.back() - b1y, 2),
                                         0.5)));
                    if(p1<pmin)
                        p1=0;
                    p2 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b2x, 2) +
                                             pow(car.y_point.back() - b2y, 2),
                                         0.5)));
                     if(p2<pmin)
                         p2=0;
                    p3 = 100-33 -
                         (20 * log10(pow(pow(car.x_point.back() - b3x, 2) +
                                             pow(car.y_point.back() - b3y, 2),
                                         0.5)));
                        if(p3<pmin)
                            p3=0;
                    p4 = 33 -
                         (20 * log10(pow(pow(car.x_point.back() - b4x, 2) +
                                             pow(car.y_point.back() - b4y, 2),
                                         0.5)));
                    if(p4<pmin)
                            p4=0;
                    if (direct_n <= 3)
                        car.direct.push_back(4);  // left
                    else if (direct_n == 4)
                        car.direct.push_back(2);  //上
                    else if(direct_n==5)
                        car.direct.push_back(3);  //下
                    car.p1.push_back(p1);
                    car.p2.push_back(p2);
                    car.p3.push_back(p3);
                    car.p4.push_back(p4);
                    car.p_min.push_back(0);
                    car.p_best.push_back(0);
                    car.p_threshold.push_back(0);
                    car.p_entropy.push_back(0);
                    car.p_my.push_back(0);
                }
            }

            }
            //cout<<c_car_num<<endl;
            if (car.car_n.size() > 0) {
                for (j = 0; j < car.car_n.size(); j++) {
               
                    //move
                    if (car.direct[j] == 1)
                        car.x_point[j] += 10;
                    else if (car.direct[j] == 2)
                        car.y_point[j] += 10;
                    else if (car.direct[j] == 3)
                        car.y_point[j] -= 10;
                    else if (car.direct[j] == 4)
                        car.x_point[j] -= 10;

                    //out
                    if( car.x_point[j] < 0 || car.x_point[j] > 1000 || car.y_point[j] < 0 || car.y_point[j] > 1000 ){
                        c_car_num-=1;
					    car.car_n.erase( car.car_n.begin() + j );
					    car.direct.erase( car.direct.begin() + j );
					    car.p1.erase( car.p1.begin() + j );
					    car.p2.erase( car.p2.begin() + j );
					    car.p3.erase( car.p3.begin() + j );
					    car.p4.erase( car.p4.begin() + j );
					    car.p_best.erase( car.p_best.begin() + j );
					    car.p_entropy.erase( car.p_entropy.begin() + j );
					    car.p_threshold.erase( car.p_threshold.begin() + j );
					    car.x_point.erase( car.x_point.begin() + j );
					    car.y_point.erase( car.y_point.begin() + j );
				    }
                    
                    //direction
                    if (car.x_point[j] == 0 && car.y_point[j] == 0) {
                        if (car.direct[j] == 4)
                            car.direct[j] = 2;
                        else if (car.direct[j] == 3)
                            car.direct[j] = 1;
                    } else if (car.x_point[j] == 1000 &&
                               car.y_point[j] == 1000) {
                        if (car.direct[j] == 1)
                            car.direct[j] = 3;
                        else if (car.direct[j] == 2)
                            car.direct[j] = 4;
                    } else if (car.x_point[j] == 0 && car.y_point[j] == 1000) {
                        if (car.direct[j] == 2)
                            car.direct[j] = 1;
                        if (car.direct[j] == 4)
                            car.direct[j] = 3;
                    } else if (car.x_point[j] == 1000 && car.y_point[j] == 0) {
                        if (car.direct[j] == 3)
                            car.direct[j] = 4;
                        if (car.direct[j] == 1)
                            car.direct[j] = 2;
                    } else if ((car.x_point[j] % 100) == 0 &&
                               (car.y_point[j] % 100) == 0) {
                                //   cout<<car.x_point[j]<<"   "<<car.y_point[j]<<"   "<<endl;
                        int direct_n = (rand() % 5) + 1;
                        if (direct_n == 4) {  // right
                            if (car.direct[j] == 1)
                                car.direct[j] = 3;
                            else if (car.direct[j] == 2)
                                car.direct[j] = 1;
                            else if (car.direct[j] == 3)
                                car.direct[j] = 4;
                            else if (car.direct[j] == 4)
                                car.direct[j] = 2;
                        } else if (direct_n == 5) {
                            if (car.direct[j] == 1)
                                car.direct[j] = 2;
                            else if (car.direct[j] == 2)
                                car.direct[j] = 4;
                            else if (car.direct[j] == 3)
                                car.direct[j] = 1;
                            else if (car.direct[j] == 4)
                                car.direct[j] = 3;
                        }
                    }

                    double p1_new =
                        100-33 - (20 * log10(pow(pow(car.x_point[j] - b1x, 2) +
                                                  pow(car.y_point[j] - b1y, 2),
                                              0.5)));
                    if(p1_new<pmin)
                        p1_new=0;
                    double p2_new =
                        100-33 - (20 * log10(pow(pow(car.x_point[j] - b2x, 2) +
                                                  pow(car.y_point[j] - b2y, 2),
                                              0.5)));
                    if(p2_new<pmin)
                        p2_new=0;
                    double p3_new =
                        100-33 - (20 * log10(pow(pow(car.x_point[j] - b3x, 2) +
                                                  pow(car.y_point[j] - b3y, 2),
                                              0.5)));
                    if(p3_new<pmin)
                        p3_new=0;
                    double p4_new =
                        100-33 - (20 * log10(pow(pow(car.x_point[j] - b4x, 2) +
                                                  pow(car.y_point[j] - b4y, 2),
                                              0.5)));
                    if(p4_new<pmin)
                        p4_new=0;
                    car.p1[j] = p1_new;
				    car.p2[j] = p2_new;
				    car.p3[j] = p3_new;
				    car.p4[j] = p4_new;
                //cout<<"yo"<<endl;

//best
                    if(car.p1[j]>car.p2[j] && car.p1[j]>car.p3[j]&& car.p1[j]>car.p4[j] ){
                            if(car.p_best[j]!=1&&car.p_best[j]!=0){
                                b_num+=1;
                            }
                            if(car.p_best[j]==0){
                                car.p_min[j]=1;
                                car.p_threshold[j]=1;
                                car.p_entropy[j]=1;
                                car.p_my[j]=1;
                            }
                            car.p_best[j]=1;
                            powerb+=car.p1[j];
                            // file_b<<car.p1[j]<<endl;
                    }
                    else if(car.p2[j]>car.p1[j] && car.p2[j]>car.p3[j]&& car.p2[j]>car.p4[j] ){
                            if(car.p_best[j]!=2&&car.p_best[j]!=0)
                                b_num+=1;
                            if(car.p_best[j]==0){
                                car.p_min[j]=2;
                                 car.p_threshold[j]=2;
                                 car.p_entropy[j]=2;
                                 car.p_my[j]=2;
                            }
                            car.p_best[j]=2;
                            powerb+=car.p2[j];
                            // file_b<<car.p2[j]<<endl;
                    }
                    else if(car.p3[j]>car.p2[j] && car.p3[j]>car.p1[j]&& car.p3[j]>car.p4[j] ){
                            if(car.p_best[j]!=3&&car.p_best[j]!=0)
                                b_num+=1;
                            if(car.p_best[j]==0){
                               car. p_min[j]=3;
                                car.p_threshold[j]=3;
                                car.p_entropy[j]=3;
                                car.p_my[j]=3;
                            }
                            car.p_best[j]=3;
                            powerb+=car.p3[j];
                            // file_b<<car.p3[j]<<endl;
                    }
                    else if(car.p4[j]>car.p2[j] && car.p4[j]>car.p3[j]&& car.p4[j]>car.p1[j] ){
                            if(car.p_best[j]!=4&&car.p_best[j]!=0)
                                b_num+=1;
                            if(car.p_best[j]==0){
                                car.p_min[j]=4;
                                car.p_threshold[j]=4;
                                car.p_entropy[j]=4;
                                car.p_my[j]=4;
                            }
                            car.p_best[j]=4;
                            powerb+=car.p4[j];
                            // file_b<<car.p4[j]<<endl;
                    }

//AVGmin
                if(car.p_min[j]==1){
                    if(car.p1[j]<10){
                        m_num+=1;
                        car.p_min[j]=car.p_best[j];
                        if(car.p_best[j]==2)
                            powermin+=car.p2[j];
                        else if(car.p_best[j]==3)
                            powermin+=car.p3[j];
                        else if(car.p_best[j]==4)
                            powermin+=car.p4[j];
                    }
                    else
                         powermin+=car.p1[j];
                }
                else if(car.p_min[j]==2){
                    if(car.p2[j]<10){
                        m_num+=1;
                        car.p_min[j]=car.p_best[j];
                        if(car.p_best[j]==1)
                            powermin+=car.p1[j];
                        else if(car.p_best[j]==3)
                            powermin+=car.p3[j];
                        else if(car.p_best[j]==4)
                            powermin+=car.p4[j];
                    }
                    else
                         powermin+=car.p2[j];
                }
                else if(car.p_min[j]==3){

                    if(car.p3[j]<10){
                        m_num+=1;
                        car.p_min[j]=car.p_best[j];
                        if(car.p_best[j]==2)
                            powermin+=car.p2[j];
                        else if(car.p_best[j]==1)
                            powermin+=car.p1[j];
                        else if(car.p_best[j]==4)
                            powermin+=car.p4[j];
                    }
                    else
                         powermin+=car.p3[j];
                }
                else if(car.p_min[j]==4){
                    if(car.p4[j]<10){
                        m_num+=1;
                        car.p_min[j]=car.p_best[j];
                        if(car.p_best[j]==2)
                            powermin+=car.p2[j];
                        else if(car.p_best[j]==3)
                            powermin+=car.p3[j];
                        else if(car.p_best[j]==1)
                            powermin+=car.p1[j];
                    }
                    else
                         powermin+=car.p4[j];
                }

// threshhold
				if( car.p_threshold[j] == 1 ){
					if(car.p_best[j]!=1 && car.p1[j] < 15 ){
                        t_num+=1;
                        car.p_threshold[j] =car.p_best[j];
                        if(car.p_best[j]==2){
                            powert+=car.p2[j];
                            //  file_t<<car.p2[j]<<endl;
                             }
                        else if(car.p_best[j]==3){
                            powert+=car.p3[j];
                            //  file_t<<car.p3[j]<<endl;
                        }
                        else if(car.p_best[j]==4){
                            powert+=car.p4[j];
                            //  file_t<<car.p4[j]<<endl;
                        }
                    }
                    else
                    {
                        powert+=car.p1[j];
                        //  file_t<<car.p1[j]<<endl;
                    }
				}
				else if( car.p_threshold[j] == 2){
					if(car.p_best[j]!=2 && car.p2[j] < 15 ){
                        t_num+=1;
                        car.p_threshold[j] =car.p_best[j];
                        if(car.p_best[j]==1){
                            powert+=car.p1[j];
                            //  file_t<<car.p1[j]<<endl;
                        }
                        else if(car.p_best[j]==3){
                            powert+=car.p3[j];
                            //  file_t<<car.p3[j]<<endl;
                        }
                        else if(car.p_best[j]==4){
                            powert+=car.p4[j];
                            //  file_t<<car.p4[j]<<endl;
                        }
                    }
                    else
                    {
                        powert+=car.p2[j];
                        //  file_t<<car.p2[j]<<endl;
                    }
                    
				}
				else if( car.p_threshold[j] == 3 ){
					if(car.p_best[j]!=3 && car.p3[j] < 15 ){
                        t_num+=1;
                        car.p_threshold[j] =car.p_best[j];
                        if(car.p_best[j]==1){
                            powert+=car.p1[j];
                            //  file_t<<car.p1[j]<<endl;
                        }
                        else if(car.p_best[j]==2){
                            powert+=car.p2[j];
                            //  file_t<<car.p2[j]<<endl;
                        }
                        else if(car.p_best[j]==4){
                            powert+=car.p4[j];
                            //  file_t<<car.p4[j]<<endl;
                        }
                    }
                    else
                    {
                        powert+=car.p3[j];
                        //  file_t<<car.p3[j]<<endl;
                    }
                    
				}
				else if( car.p_threshold[j] == 4){
					if(car.p_best[j]!=4&& car.p4[j] < 15 ){
                        t_num+=1;
                        car.p_threshold[j] =car.p_best[j];
                        if(car.p_best[j]==1){
                            powert+=car.p1[j];
                            //  file_t<<car.p1[j]<<endl;
                        }
                        else if(car.p_best[j]==3){
                            powert+=car.p3[j];
                            // file_t<<car.p3[j]<<endl;
                        }
                        else if(car.p_best[j]==2){
                            powert+=car.p2[j];
                            // file_t<<car.p2[j]<<endl;
                        }
                    }
                    else
                    {
                        powert+=car.p4[j];
                    }
                    
                }

//entropy
				if( car.p_entropy[j] == 1 ){
					if(car.p_best[j]!=1){
                        if(car.p_best[j]==2&&car.p2[j]>car.p1[j]+13){
                            e_num+=1;
                            powere+=car.p2[j];
                            car.p_entropy[j]=2;
                        }
                        else if(car.p_best[j]==3&&car.p3[j]>car.p1[j]+13){
                            e_num+=1;
                            powere+=car.p3[j];
                            car.p_entropy[j]=3;
                        }
                        else if(car.p_best[j]==4&&car.p4[j]>car.p1[j]+13){
                            e_num+=1;
                            powere+=car.p4[j];
                            car.p_entropy[j]=4;
                        }
                    }
                    else
                    {
                        powere+=car.p1[j];
                    }
				}
				else if( car.p_entropy[j] == 2){
					if(car.p_best[j]!=2){
                        if(car.p_best[j]==1&&car.p1[j]>car.p2[j]+13){
                            e_num+=1;
                            powere+=car.p1[j];
                            car.p_entropy[j]=1;
                            // file_e<<car.p1[j]<<endl;
                        }
                        else if(car.p_best[j]==3&&car.p3[j]>car.p2[j]+13){
                            e_num+=1;
                            powere+=car.p3[j];
                            car.p_entropy[j]=3;
                            // file_e<<car.p3[j]<<endl;                        // file_e<<car.p3[j]<<endl;
                        }
                        else if(car.p_best[j]==4&&car.p4[j]>car.p2[j]+13){
                            e_num+=1;
                            powere+=car.p4[j];
                            car.p_entropy[j]=4;
                            // file_e<<car.p4[j]<<endl;
                        }
                    }
                    else
                    {
                        powere+=car.p2[j];
                        // file_e<<car.p2[j]<<endl;
                    }
                    
				}
				else if( car.p_entropy[j] == 3 ){
					if(car.p_best[j]!=3){
                        if(car.p_best[j]==2&&car.p2[j]>car.p3[j]+13){
                            e_num+=1;
                            powere+=car.p2[j];
                            car.p_entropy[j]=2;
                            // file_e<<car.p2[j]<<endl;
                        }
                        else if(car.p_best[j]==1&&car.p1[j]>car.p3[j]+13){
                            e_num+=1;
                            powere+=car.p1[j];
                            car.p_entropy[j]=1;
                            // file_e<<car.p1[j]<<endl;
                        }
                        else if(car.p_best[j]==4&&car.p4[j]>car.p3[j]+13){
                            e_num+=1;
                            powere+=car.p4[j];
                            car.p_entropy[j]=4;
                            // file_e<<car.p4[j]<<endl;;
                        }
                    }
                    else
                    {
                        powere+=car.p3[j];
                        // file_e<<car.p3[j]<<endl;
                    }
                    
				}
				else if( car.p_entropy[j] == 4){
					if(car.p_best[j]!=4){
                        if(car.p_best[j]==2&&car.p2[j]>car.p4[j]+12){
                            e_num+=1;
                            powere+=car.p2[j];
                            car.p_entropy[j]=2;
                            // file_e<<car.p2[j]<<endl;
                        }
                        else if(car.p_best[j]==3&&car.p3[j]>car.p4[j]+12){
                            e_num+=1;
                            powere+=car.p3[j];
                            car.p_entropy[j]=3;
                            // file_e<<car.p3[j]<<endl;
                        }
                        else if(car.p_best[j]==1&&car.p1[j]>car.p4[j]+13){
                            e_num+=1;
                            powere+=car.p1[j];
                            car.p_entropy[j]=1;
                            // file_e<<car.p1[j]<<endl;
                        }
                    }
                    else
                    {
                        powere+=car.p4[j];
                        // file_e<<car.p4[j]<<endl;
                    }                  
                } 
                }
            } 
            c_b_num=b_num-last_b_num;
            last_b_num=b_num;
            c_e_num=e_num-last_e_num;
            last_e_num=e_num;
            c_t_num=t_num-last_t_num;
            last_t_num=t_num;

            total_car+=c_car_num-300;
            file_b<<i<<" "<<c_b_num<<endl;
            file_e<<i<<" "<<c_e_num<<endl;
            file_t<<i<<" "<<c_t_num<<endl;
         }


    double avgmax=powerb/total_car;
    double avgmin=powermin/total_car;
    double avg=0.5*(avgmax+avgmin);
    double avgb=powerb/total_car;
    double avgt=powert/total_car;
    double avge=powere/total_car;
                    cout<<"AVGmax   "<<avgmax<<endl;
                    cout<<"AVGmin=  "<<avgmin<<endl;
                    cout<<"AVGpower=    "<<avg<<endl;
                   cout <<"powermin="<<powermin<<" car_num   "<<total_car<<endl;
                    cout<<"b_num   "<<b_num<<endl;
                    cout<<"powerb   "<<powerb<<" car_num   "<<total_car<<endl;
                    cout<<"avg_b:   "<<avgb<<endl;    
                    cout<<"t_num    "<<t_num<<endl;
                    cout<<"powert   "<<powert<<endl;
                    cout<<"avg_t:   "<<avgt<<endl;
                    cout<<"e_num    "<<e_num<<endl;
                    cout<<"powere   "<<powere<<endl;
                    cout<<"avg_e:   "<<avge<<endl;         
        file_b.close();
        file_e.close();
        file_t.close();         

}