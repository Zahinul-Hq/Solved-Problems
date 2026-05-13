#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}

string func(int key, string Message){
    bool r = 0;
        if(key < 0){
            key *= -1;
            r = 1;
        }
        key %= 26;

        for(int i = 0; i < Message.size(); i++){

            if(isalpha(Message[i])){
                char st = 'A';
                if(islower(Message[i]))
                    st = 'a';
                char ch = Message[i] - st;

                if(!r){
                    ch -= key;
                    ch += 26;
                    ch %= 26;
                    Message[i] = ch + st ;

                }else{
                    ch += key;
                    ch %= 26;
                    Message[i] = ch + st ;
                }

            }

        }

    return Message;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	string BatchName, Message, ky;

    	cin >> BatchName >> ky;


    	getline(cin , Message);

    	ky.pop_back();

    	int ckey = stoi(ky), key = stoi(ky);

    	cout << BatchName << " " << ckey << ": " << func(key, Message) << endl;
    }

    string s = "WMuz 2468: Y,Ap9k-:LuWlx3RFoXXoQCM!-Bt2hXEXAd6.Tt,n7AnU zAxSfXP!9hy:91XxuLqiEt1u57KlAViWGcwnrw0ogW2;0o:bMcfK6soYbK3GiKl6zrI6JI14eSOE YXi67,a3fWTiNJXfxmO9gyXY:?1pJMDYj1mje7dZF1JO?gLPdbfJBznox6h1f;u.B,d9O3?  Y;ZNFP5BvfvPv4Vsl.V43G6DmaFrONKdVgU9RfXTZLoq6r2iP:XE:cVmYaPVxc8dfsgNozZGAnHxPz86:Lm9Y-:0vjNmR8bDybzjtD1FXc;I9qm9D2tCWz1VKNKI;XZLhR-aCeIWi5X15hxthtYzw5lALVgN2?XQuw,tO;gpc2Je:YDAqysmS!nfWYl:TVap9NL4WKH62cZ!T8gWV1EgV0VBgOdXl;xI9FlXTl4A4U;ZVMwH.sp:sxD7-BB6BjlO05Ck?0.mS dG!NX5!u?oZxv9foXLFeJY.oj,upW.i3vrRI1MJUB5qB7hIJO9KexEsbpCSWUrATpn1:ujQSrulgomTOgch39lz aMjpa!DG8tLGnrIIDfz:5kd;;u.5jKIq0K0fa9-YD!F0vZLzknxyAXmRFPHL?uAA;.6EPLDKVKdpVJvtT5qiOMuCQTL;MEiJ9lO9OBNGuEplezR t!QO5odYLWDUCU,;wJNS!FzDVFFBV6PLo.cJjNYemAfbb1AR3n9.Rv,UMA-KJTz! -J5K:kMqcrd6tuAixbNCq?c9AM8h?K,tQ0r sV5MOmGiMB88nbShv08RW5DFW;G:XhI9moqfd7jTSjSrC??J3aq6Uk7;r0m2B1cn.VSwaQapBkLbIhd.6bS4205djZjx: awNzsR NnqeUlTt0oHK5FeTJc6uzsRTKrPG0CShX3OxOIobjBKiRz;ZAARo,!87;8zCJ,;;jXh.dGKh!pSqqIEgTvXVdcyPv;vQF:xq7xCAm5iww6NPst-kGnxzXZa9t2Mdh5q1xOsZ2SaaHP5qSgv8VTGNNssqX65Y;.eHQ 95XUxd7:SFB osPlJWuM 33j48z59Q-pLQNeXNjFvmAS61HDZj-oNSoHpXF-2iTgQGikc FxeeRbZk9W-GH2u7xe4axqNvCdSgah-N h0b:g2npM-wzPYau,sj;uCe 0mhIsHCh44j?;fVo6dp-o-xk1tzupW4-9YsJmK9?tA;HwJ,gq-StvX7HbEKv9TEU!Jp?qFmqMIvmi? KA7yZyMW8-2:Uxg9P-XSsNNaSQV?Ht.menZXEiW0pTNw-l4VJS8tBAFOqNDkQdDrGwpte!9lOgtQZK:QFUweh26 uu5W9BKKte AtfdZkbsl:QpIgVWyobo38LjMp1 CurWGa2ckVaEow-5,XelrxIhJ.qLmf!L4R!GBf8DaMwbQ2mSS?w7zgaE853RBYki7q?be:XFSSBAmhPM.Bh99PMcBx6AaUcHC F?TG:bytmz6MHgP4RFM1!RUdzddOHRcqV2fK6AuxshtU2Nl;hUJgjt3jqTw.dbTS?Iu,xDe;NpH9ql-q;tFGqcBSRvorSORCmEapZ68bNZpr58K!xGmwL:91W.vg;6Ou !99G2: FBkw:PpSiuPLfu8QN1p1H62yPqSWpJMIXFvl-XWdzktbjAXa!.u-cdjaVbI5R16AD rqGSCRj1k04,ka-3GFatm6!f2dlNyDxio! .RA5EK Od1MZep zzBY5n6ldO4VycI1U,gqjJo6PpsUGURg9l9CpZQb;XuTAL2HG !GmVIe!YnI:n386WHa;VJepnjNQboRb3?piVV-OtObNmmU9LhTxCDe!7KbwCBQFp;!OU:-5GMCzbH;koHxjNQvyFY?ogGPV.F;4MiNZbo0;DNoLpeLU:tXXhGU,:8uqyl1AsANk4Aau,anRKV1UZ2vglOWMVO2mo jwPzN4k1pRwBPwzK,?nrq,Ixijvz0CKgZH!X6Rzf86Vb7VmE.t0OVDTuJ2:kvIxjKnIHgO36XTAZP9:hVq1Gz5QT:cHatGqTKIpmXSzjX5MbLR862LTCS486TdCM:.B25qg2z0ftgCTR,Tbn3pm?MycQleUdT5kJxEv.-S!oYK5XYzdW5:WIsry jnnYN3S723C5:IEoMxa,6YIZHttRO76ZKtP8AQ6oqs9!a.hMhXPMPWNjM!kJUpkFRbu1ns9h6xhA5f8qDnnTtxftwUvQZuCmMeD2A1eKN2HcgQ9Ne0QWMwjTKsoCk8CR9cTo:TgxukSsfIhOMTY-n-WGsWBMj.ERLNs!BoRyQ1!.?HVlzLG.-v1rYlpzJ,SpGe4K46wlv,zjwpXRkztNEiW.Supx7qn5 A9:V9x3hcbEuR!5e,XVZkC7YGOJZhd48EYeNCjGitTJMF2knviaqAG!9XHgGvxFjbYvX4jDbMI7z4V,s!7.jSiN2t4Sm!fveT7IaFPx6-I6WVuun0AAFlP9Y.5ql ,7yg;-PWLuTOpfD!SPeMhrQiYTx!Be8sFfRSUxLT6gQV-Eh:cu9qeOr:olWV0TfgJAk!2L7Tf:dpJcSHrj97OVkils6P.-K6pBLRS7C8Y:tWE2rJ14Sna3FncVBgNzBQuGRw.1!odqP.8sOURoof9nAZbd3k-l51PN5ZAosBKEH12oQkZ.LuRszhA93:OW Tes0Og-1lO5;bh7nZ81mbKEiy-7cpiuxGpQ44KNmPHp3 vDFvrwvmB1nbk8G8Zae8EHEDUK0x3zQ9VAoFFAElzC6m 7qEmpDAdKNfYWdyL:yisKd;s3ep5n4-P:Zlnqgz2TGm2kHqKgiFWY4z;Mrkt 9M;ZJXVq-GrdNbwA-;UBfz4nVd9Xnw!WjPbyYht3k3o1IZnjszvQmgoi?UUKIKKDG4WT6jGAYNhy3JqBEt?ohCWjhX7A,k5r7Fqq:Q HKG,bKBbiRG5bBbuf-s 7E9o91pVmnK5rAMJVR5!qL::7bbjfW7DA9kIAf1!q1EMbXYLNWzuyUSl24?qW1tmFZB6paEmidz1zhgG6DrmdxiLiEZ3be0rx5tZUQqaW0;FBEzytBxWsY6,k-bQshE?GS,NPGGCjgs:19sPX4CRdASvFaCWhyxBRNlIPKOELINbxshuf?,dbTJlg-w9jXm163siWFO rhIYacRitSNz?!ynKbWZPgXuS?227!few2OwBiNLBB8JhgeOhU x:?!Jr9SZIfrXUsV.B z3C,cW.7; MeVKaoeC.FKLF-u.6kvYXoX3d51?5Z:1ZTP!gj5a1dekLs;o,FYKM?dCwX sCSEz?, ;xNLX1nG8,BZAo!Lt:rmu-pM6;:xI?8Tnfz-ZRKd?EF;bhjl2V1u?u31W4mx5S4nF9kF8SgDGnFtBPZYX5DpKSrNd4Mj4w!s0utPd4C 6aKw1weGZ7hLv,eaLtSBAgg nRPJrUGB0L95;i7pU1T0NecWDDPHRYc:9JZ.D3DCcNooToWqOO!Mi3QKHt5to1NFh1OGQxYsB9Q2ZI-7Ppl?uY94!T4w.kzE-lKVCb9n?:NQFs1js6?5QclqZcT:iB9KqewfeJHvH,k6RY:6Ve6s38TdL!lwWS!CGzu9 Id45OcjFGsfhqFEcilYZYAga-2?2tpgF295o Lu:c :6wMh;WzglLB5O2pdGqB0VqxjZ67p0k7vDxH,7GUu30Lhhqjv2M,!e06Wyv;bN7qT7u4f1xc4nkC9CSGUwj7iqT c2O6wFce.!!?60r; m;;ysXBk!.DUJBEQPMzSTQQBQS!XEtbqQM4A9,9WPh..zpR4L9!:-melLN!ysI4qh5ePUIywNjC-2f,1cm3x4qNgOPvHlHrVFKZfhTpW,uuUGG:Gjizlo-0dxSPvbWjz8qPx68I?PADtkgELUPcNfp04xj0GARcIQ?xU7SissoAYbAxT9vZ-ilotmxj,7S,QjEyb8P7-uLuR.Z!rr8wFAXfPRNYx8Hop.kHMq.d-Q:nT:OA4,bGaP.LOSwc1CiSo6nSN8rqLLEOy,x2YbjKap-OjkvKQ!emP!GZZnxClsxLTkHxxJjRpswBNK6V7uj8WR;X56hMty4X?nAAIW 8V3blpleUNzPiKUf69 pKvyFeFA:z!flA;nqsjTopb!VbAkYLkApsBzMVmQV!0lW!TWj.3v4R99El9c,64Xc-lqyVVD2hJyAUJ7l7NyZzUcD92dBhzN0SQ3B2.EWBJX3Hldgc;YFAWXd9xaS9Yc7W!eIIcyM2uaPyGHsXRLE1d?g:5ahvemAR4L-jV-!.tmODnSV.x7apQxmwUhs2GpCbiHtdKcPw?9iTv6MbQmUBZiL;f,z3AqifG5bE uIm5cE1v05X3bs;er1zz:oUZ?W0wzHVHIcRxP9cOME0nn8Lnt-YwldWVgDqSqDGBWUOzsm;:ysA:l5R0YVu1ZOFOWfyfaaC3-cwp49FJn2H0pPE1D-sEMO8D;n pxYa;NcsUPNom.LtSMnB;rlFtmG15Em,CGk,0?zw6yH9mZhTi1F!!mmo82MNF!gtDz4oWirp6j j Y-x.;7VjmqA 50X Mz9RlbLvsr!xjGE.yk-f-ZSjHYSYG6fSmnlzJD-mX-bGejjmTNw9TGKb2w;09of!Ngxt83?fGM?Vh Vtl!9W4t9? xQ5A2ki fev4QNfmJrK8IKueMBBBdf O5ePpARJE-ku3vL7-vkX3uMsJI 1RfvC4N,GZmST4OewVzbRJDat6?iO.NY6o  ws6fN9aKNx:3Poj;8nuADFf9Q?K nxlG:?cVKA.uNLVCcoF.eJg:9gZYY2c;d38BYMpD9uNmmgKK 9U72h,L6Y1fl8NBzFYSsz5lLDqs8CM:X1N.8A0wCLJU7 JgiHAPdtcQe4fzop,EF.3I0qGN6ZumqET EFhZop82jSONO,YFtRL!Wr9jZsWaiwDezvDFhwhd:h8xC?S0rx8.OgnP0 8xZphoQBzW2cDNF8GxTcS5e95N; xwycw,AC3rdzRYc;93a!snVLfnaL7re-WPNEo9ApCKBro17F0kJ-G LIYayhG!Rq2ZY8;eof! O44..y2bEP6sK9TI1,QY8NR;ti?U2.9Kl.AGqjUjnui.F3F4j.N4coKoQlZAE L:!PY-!qEWr76Q?!Qwo9zLkkR;T5MRB272iVnZmaH-V8QUFDDDkQO35jUswln10iT;UK1?eVu5LJSbsF8B3mb0IRrHB3etl53;n2yZpllF.aH?mid0JV.:NxLEW1Vi0ERkNm?dThYYiek:ic3hZVLpdIQ2Z?RaOm?KYbb9m1cBf3cC!gobkI2pCo7w2wlij2N1!?WHtc;ygG.x01YlGR jqvIlzFk8F7 Ml:Pk5UTYuLjqD5KhiPL;nQ5M4!r:P.oxz!UN3FGr5h:nzC:-MCR uJK0Q6ril;86E4ONIy:mPAg03bArVcArRhetQ1?Q-1nD3EzJDmtOFXyc7tdeaB--uNrg-TP9M7qfG7zuhsLaiXz.-ZKT07-X3Bcvw:mCM?hwFvbNwDb i,VbLPupD0ftBbMvMuNmltuuazXVU7xmL7xo-FbBl!OSsEJe!u1h7AihNDz8s8Y C.CHhs?QfPHprC0UGhBFg?Jgsn4WgvV5cG-?eRciPekxjxHqG3USU!.GL5zycB9NGf8:eluzBnRo;9ws,a-x!:0,GqGl-T ei-u03BJB5Kq2Dj::6.zSRVIrKARoYlNzNFaAsAqtqhr7!v:7fgB10FW,qfcJ85uZLP;fUUC1ta-HurJm WndcWVrUhkNZw0t4:E1,blkXE:CltF-2tOmtS-OyKoGDEf6g8eGf,b64YMyRg1b,n-PC90sW:639:9ehybL:otC9Alh-4i92WgunkwEgEMOglO0Uf.AFHKvXZPvdvl:cuPSRUZ3HOVEML:!06cxjpGCk9AXUoiQOwtx-92CRd6DW S.uz5LvFc6o3i vjJENndPoK8y0Xs9fClU88ne:s?ARGlcPCrH Jro0 j3W2SuAbh9Nh!FDMzD;E6Q-?RPYdZQVPGKR8UmWBZxmU3r-1tcHcQ5c. RSqkc21.RAHuSQBWbwCz957JGSRcUmr-BiZj3u4cnDR7gSI??l8,zCve?hSB Bz:.;.LtM7LK.rNSBw?LeprOIX0,:qaAT8mkZ0:BEuWH1reP2Rmi!BKy0ew64,e3iSORmC6mlb1pmhoEDk;l.IH?3c z4sHQTaTb!7FHbgEoP WS7.kFp3f7?oQXLxckL?QEDhziPQod8Oyn4 Es5T-2a-1Dp.NVKAy8tocE-osMoLZn!X,E:VsjV9D,L;;1sj349Ie:5HGX!V6bqU,1GQNFKK9TQWJ1R-?Uj,fx7TDD0rd5S9Z:GbaDcvrDhsmIi.CWY?pF5pFp;3kIBRKPR0RYeuWl9gqYwIJ::KDEQrFpPlRc7OVlVkw4lVMmpS,!K,erpPf1p0.lk8Db4PdelBwdPNFGQnYahPzVRN4ttGwH6pzHUmAt,f;uU,Arb0Z;s0HA-sIl8ekq61K.,dj4P4oX7qICr,7jNOk4BM!n5y;VZwvsBQQseW50I3fSt-Qfv2HACPqb:Gzw. 7n-aINs0JgUD9nUUumwq M7ZXcD8yjT9;a9GF9.m?iowkLXdEdonw4v!chkulg!ytMSlv59IJ5mO UQzokDDZ.Mn H5R-?0?C35 kx0j;ac3YQiNVNi54jrLRBz8M;x4D,9..hSfrX692AK7ZeFcvoN1abfiq:G!1Ky9v5Y!-ux9KZpmPtE;sCRMd0wO76r8ynMv:eUR,8x7i9x2zPM52Ab85O;UVIWBOD0UW1Kyt;7XA3s9Knz0M?29h6jrLX1Z7SyI.BxsH PPsSNh4,CH6WS,t8uVN94,zcqNQ QPq2- zxSXQ6C1GV7VyPnFIsM.kStQU53cnPs!!QelxXZ95nd4xPpJ0IYTljbrr1wbZ4NOck14rGhHXj7sAn6T8XJ:m.WBat6uFpZH,1YKLPyqM:IE?yq3xWw0Hp4rkTPE.1wMvOxOP6ajVfv6T:HuQY0ywwGsXXN!!dOXUqIvOHm7s1Wg9ybHqqrGaKx ? W87aySBXb?dcquu.mje7mD7y;zavPO:gzNM WOrd2qAAuAA98:NC8.:9Q54c0ONMTXfFk907OeFiqZuH84zZfUffw6.wyBLaJ6rV2VdxM?pkG:!mAXD 0lKxS-DnxkfqdP73WUz0hcT,rocJ7xnXz10WYuhNFjM1Vpp?kihpT?5FpaAN45aA8ynKi,kKEy.JeENgcXZfrGPCBQ5oKny6Rhre!Uhhy6B?.VhzCfPvCIn5rTZ4d,3KlQ.BN.!m75En0DeAkGMH4L:VK 2RQ?WFQQiMjXCrpMij99TsvWGj780h-w,6k6T?sSqG.46U !hvWR,fhGZ:ys-8YEK?PDUIpaB,v:j.!e-WRxyER.eCX1blN!haXcK09FmaLgqx5f!tsXC0rBOMXz8r?,x-sLB4-HwrFtsMd3vwtDG0.sodqjb:8IOrYODv wG8AP0Bj8.Tfvcr30TZZBG158-jYsOkAM,;3CgviocfUirG3VizSOI15Hyw1ehP!GQPnxMw1xhDxMz,VuDixnfFOHpH?J5V45aWj?3Jmyj:;Oq5f8ZFR7Q7lPW;tJCS!wRRSLdeXzrU2z2pyOTpxj0yj94AmUnjuhXuKHzeVtGmzTzqcIhCcJ2:0QBaYAub:qeMOVeoWwpw-sZn16.I2JDBIX8;ca0co?VvkWdWfh-at1PK?r1VMnBDXUbt2yJS yM1.UpBWZ1Vy!!,EZkc Kmz6F.ZD lMG54mc8O87bgy;bDv4-VQEwT14ZpcDpdcnMA?LkB-Mqljzx9Woatt 5fYPLN?;rR:soZqE7Ey1mDMbGdtnrao8U3mNUDVuOgDonD0QDNbYEJ.acZAXgCUay.goQNUYfH?Eh!gjWVyffRiuVGl6c;:nfBdpf0nhdWHD99kyL8oE2TmcP8e:1.GE1PdXk9kR,PObsYbcsHF9iEmGjo7HSXneZZqvG6,bz.Zjr:jNAaWu?h6yJYUJgsClLx9:9;QZkQY5CCD?U!VekBrOOro.Pi9I;!O5YV mlU9!GU5zdAz30V0ixC:TJrcd!Tr-:6DePg 524:XKb,NVn57a8CCip1jJRABXj1fHmUlP4cf20kGC;EjhyuxHqV3P3BBDS8BMI4vJRDT:ZvrBYTkp:7Xjy83UE-Ct 2Vdd2UskuLu2;V6pN9C.D:gy!za6GSri056pPQ-9YA.MVZAANSIf!p3fyzLMBQ28RArsDd4Fa;GO;S,nVZ.?3N,ViZ;omjCUJ?S.Z5AeqhDN86Qlz3K8pEJNn6rlc2tEqtXrFDUXEASloP0YH!-56INPTVO,?BiZzU:SV6BHfTfSlDJLG5OEDn1Zc37C!fHd.T;Y3lWweDadp-4ppT-u8w qEORaVZsH9i!1HZQ,A.JZm4vMl!mIo3ToRmCjZDhMhALaBqcBbg?NpWjI:;5Qn,lH9Sjf;aptImbBRDsUHgRukcFvvKjOH!yyMKXyqqA:;,GCw -UgRqhEkjMqhrEru0R 8x!3f1kRc06FZ7m5fTRG3nM8J2CvCbSFlLpGSeYj7cnCb2T vqJ:57Z3MAUIPF-SQw,FzhBpVVICw. ZGyt7DKOKUX!b;DwIulRUC;ENoyMH3KE0I eHCnc8O!oa0b7USs33yy9r6af8t;Zw;FoQ3bb";
    cout << s.size() << endl;
    return 0 ;

    runtime();




}
