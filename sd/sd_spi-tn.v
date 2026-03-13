module sd_controller (
    input wire miso,
    input wire card_present,
    input wire card_write_prot,
    input wire rd,
    input wire rd_multiple,
    input wire dout_taken,
    input wire wr,
    input wire wr_multiple,
    input wire [7:0] din,
    input wire din_valid,
    input wire [31:0] addr,
    input wire [7:0] erase_count,
    input wire reset,
    input wire clk,
    output wire cs,
    output wire mosi,
    output wire sclk,
    output wire [7:0] dout,
    output wire dout_avail,
    output wire din_taken,
    output wire sd_error,
    output wire sd_busy,
    output wire [2:0] sd_error_code,
    output wire [1:0] sd_type,
    output wire [7:0] sd_fsm
);
    reg [5:0] state;
    reg [5:0] new_state;
    reg [5:0] return_state;
    reg [5:0] new_return_state;
    reg [5:0] sr_return_state;
    reg [5:0] new_sr_return_state;
    reg set_return_state;
    reg set_sr_return_state;
    reg new_sclk;
    reg scs;
    reg new_cs;
    reg set_davail;
    reg sdavail;
    reg transfer_data_out;
    reg new_transfer_data_out;
    reg [1:0] card_type;
    reg [1:0] new_card_type;
    reg error;
    reg new_error;
    reg [2:0] error_code;
    reg [2:0] new_error_code;
    reg new_busy;
    reg sdin_taken;
    reg new_din_taken;
    reg [39:0] cmd_out;
    reg [39:0] new_cmd_out;
    reg set_cmd_out;
    wire [7:0] data_in;
    wire [7:0] new_data_in;
    wire [6:0] new_crc7;
    wire [6:0] crc7;
    wire [15:0] new_in_crc16;
    wire [15:0] in_crc16;
    wire [15:0] new_out_crc16;
    wire [15:0] out_crc16;
    wire [7:0] new_crclow;
    wire [7:0] crclow;
    reg [7:0] data_out;
    reg [7:0] new_data_out;
    wire [31:0] address;
    wire [31:0] new_address;
    wire [7:0] wr_erase_count;
    wire [7:0] new_wr_erase_count;
    reg set_address;
    reg [9:0] byte_counter;
    reg [9:0] new_byte_counter;
    reg set_byte_counter;
    reg [7:0] bit_counter;
    reg [7:0] new_bit_counter;
    reg slow_clock;
    reg new_slow_clock;
    reg [6:0] clock_divider;
    reg [6:0] new_clock_divider;
    reg multiple;
    reg new_multiple;
    reg skipfirstr1byte;
    reg new_skipfirstr1byte;
    reg din_latch;
    reg last_din_valid;
    wire [5:0] n59_o;
    wire [5:0] n60_o;
    wire [39:0] n61_o;
    wire [31:0] n62_o;
    wire [9:0] n63_o;
    wire n64_o;
    wire n65_o;
    wire n67_o;
    wire n69_o;
    wire [7:0] n70_o;
    wire n72_o;
    wire n74_o;
    wire n75_o;
    wire n76_o;
    wire n77_o;
    wire n78_o;
    wire n79_o;
    wire n80_o;
    wire n81_o;
    wire n82_o;
    wire n84_o;
    wire n86_o;
    wire n88_o;
    wire n90_o;
    wire n92_o;
    wire n94_o;
    wire n96_o;
    wire n98_o;
    wire n100_o;
    wire n102_o;
    wire n104_o;
    wire n106_o;
    wire [7:0] n108_o;
    wire n110_o;
    wire n112_o;
    wire n114_o;
    wire n116_o;
    wire [2:0] n118_o;
    wire [1:0] n120_o;
    wire [5:0] n122_o;
    wire [5:0] n124_o;
    wire [5:0] n126_o;
    wire n128_o;
    wire n130_o;
    wire n132_o;
    wire [1:0] n134_o;
    wire n136_o;
    wire [2:0] n138_o;
    wire n140_o;
    wire [39:0] n142_o;
    wire [7:0] n144_o;
    wire [6:0] n146_o;
    wire [15:0] n148_o;
    wire [15:0] n150_o;
    wire [7:0] n152_o;
    wire [7:0] n154_o;
    wire [31:0] n156_o;
    wire [7:0] n158_o;
    wire [9:0] n160_o;
    wire [7:0] n162_o;
    wire n164_o;
    wire [6:0] n166_o;
    wire n168_o;
    wire n170_o;
    wire n171_o;
    wire n172_o;
    wire n215_o;
    wire [5:0] n217_o;
    wire n219_o;
    wire [31:0] n220_o;
    wire n222_o;
    wire [5:0] n225_o;
    wire n227_o;
    wire n229_o;
    wire n231_o;
    wire [5:0] n234_o;
    wire [5:0] n237_o;
    wire n240_o;
    wire [1:0] n242_o;
    wire n244_o;
    wire [2:0] n246_o;
    wire [39:0] n249_o;
    wire n252_o;
    wire n254_o;
    wire n255_o;
    wire [5:0] n258_o;
    wire [5:0] n261_o;
    wire n264_o;
    wire [1:0] n267_o;
    wire n269_o;
    wire n271_o;
    wire n273_o;
    wire n280_o;
    wire n282_o;
    wire [5:0] n285_o;
    wire n287_o;
    wire n289_o;
    wire n291_o;
    wire [39:0] n294_o;
    wire n296_o;
    wire n297_o;
    wire n298_o;
    wire n300_o;
    wire [5:0] n303_o;
    wire [5:0] n305_o;
    wire n307_o;
    wire n309_o;
    wire n310_o;
    wire [5:0] n313_o;
    wire [5:0] n316_o;
    wire n319_o;
    wire [1:0] n321_o;
    wire n323_o;
    wire [2:0] n325_o;
    wire n327_o;
    wire n328_o;
    wire [1:0] n330_o;
    wire n332_o;
    wire n334_o;
    wire n336_o;
    wire n338_o;
    wire n340_o;
    wire [5:0] n342_o;
    wire n343_o;
    wire n344_o;
    wire n345_o;
    wire n346_o;
    wire n347_o;
    wire n348_o;
    wire n349_o;
    wire [5:0] n351_o;
    wire n353_o;
    wire [2:0] n355_o;
    wire n357_o;
    wire n359_o;
    wire n360_o;
    wire n362_o;
    wire n363_o;
    wire n364_o;
    wire [7:0] n366_o;
    wire n369_o;
    wire [5:0] n371_o;
    wire n373_o;
    wire n376_o;
    wire [2:0] n379_o;
    wire [31:0] n381_o;
    wire [7:0] n382_o;
    wire n385_o;
    wire n386_o;
    wire n387_o;
    wire n389_o;
    wire n390_o;
    wire [2:0] n391_o;
    wire n394_o;
    wire [31:0] n396_o;
    wire n397_o;
    wire n399_o;
    wire n400_o;
    wire [5:0] n402_o;
    wire n404_o;
    wire n406_o;
    wire [2:0] n408_o;
    wire n410_o;
    wire [31:0] n411_o;
    wire [7:0] n412_o;
    wire n414_o;
    wire n416_o;
    wire [5:0] n418_o;
    wire n420_o;
    wire n422_o;
    wire [2:0] n424_o;
    wire n426_o;
    wire [31:0] n427_o;
    wire [7:0] n428_o;
    wire n430_o;
    wire n432_o;
    wire [5:0] n434_o;
    wire n435_o;
    wire n436_o;
    wire [2:0] n437_o;
    wire n439_o;
    wire [31:0] n441_o;
    wire [7:0] n442_o;
    wire n444_o;
    wire n445_o;
    wire [5:0] n447_o;
    wire n448_o;
    wire n449_o;
    wire [2:0] n450_o;
    wire n452_o;
    wire [31:0] n454_o;
    wire [7:0] n455_o;
    wire n457_o;
    wire n458_o;
    wire n460_o;
    wire n462_o;
    wire [39:0] n464_o;
    wire [22:0] n465_o;
    wire [30:0] n467_o;
    wire [39:0] n469_o;
    wire [39:0] n470_o;
    wire n472_o;
    wire n474_o;
    wire [39:0] n476_o;
    wire [22:0] n477_o;
    wire [30:0] n479_o;
    wire [39:0] n481_o;
    wire [39:0] n482_o;
    wire n484_o;
    wire n486_o;
    wire [5:0] n489_o;
    wire [5:0] n492_o;
    wire n495_o;
    wire n497_o;
    wire [2:0] n499_o;
    wire n501_o;
    wire n502_o;
    wire n503_o;
    wire n504_o;
    wire n506_o;
    wire [3:0] n507_o;
    wire n509_o;
    wire [5:0] n512_o;
    wire n514_o;
    wire [2:0] n516_o;
    wire [5:0] n518_o;
    wire [5:0] n521_o;
    wire n524_o;
    wire n526_o;
    wire n527_o;
    wire [2:0] n528_o;
    wire [9:0] n530_o;
    wire n533_o;
    wire [5:0] n535_o;
    wire [5:0] n537_o;
    wire n539_o;
    wire n540_o;
    wire n541_o;
    wire [2:0] n542_o;
    wire [9:0] n543_o;
    wire n545_o;
    wire n547_o;
    wire n548_o;
    wire n549_o;
    wire n550_o;
    wire [31:0] n551_o;
    wire n553_o;
    wire [5:0] n556_o;
    wire n559_o;
    wire n561_o;
    wire [5:0] n564_o;
    wire [5:0] n566_o;
    wire n568_o;
    wire n569_o;
    wire n571_o;
    wire [31:0] n572_o;
    wire n574_o;
    wire [5:0] n577_o;
    wire [5:0] n580_o;
    wire [5:0] n582_o;
    wire n585_o;
    wire n587_o;
    wire n589_o;
    wire n591_o;
    wire n592_o;
    wire [5:0] n595_o;
    wire [5:0] n598_o;
    wire n601_o;
    wire [5:0] n603_o;
    wire [5:0] n605_o;
    wire n607_o;
    wire n609_o;
    wire [2:0] n611_o;
    wire n613_o;
    wire n614_o;
    wire n615_o;
    wire n616_o;
    wire [5:0] n619_o;
    wire [5:0] n620_o;
    wire n622_o;
    wire n624_o;
    wire n626_o;
    wire n627_o;
    wire [5:0] n629_o;
    wire [5:0] n631_o;
    wire n633_o;
    wire n635_o;
    wire [39:0] n637_o;
    wire [5:0] n640_o;
    wire n642_o;
    wire n644_o;
    wire [39:0] n646_o;
    wire [22:0] n647_o;
    wire [30:0] n649_o;
    wire [39:0] n651_o;
    wire [39:0] n652_o;
    wire n654_o;
    wire n656_o;
    wire [39:0] n658_o;
    wire [22:0] n659_o;
    wire [30:0] n661_o;
    wire [39:0] n663_o;
    wire [39:0] n664_o;
    wire n666_o;
    wire n668_o;
    wire [5:0] n671_o;
    wire n673_o;
    wire [2:0] n675_o;
    wire n677_o;
    wire [7:0] n680_o;
    wire n682_o;
    wire n684_o;
    wire [31:0] n685_o;
    wire n687_o;
    wire [7:0] n688_o;
    wire [7:0] n689_o;
    wire n690_o;
    wire n691_o;
    wire n692_o;
    wire [5:0] n694_o;
    wire [5:0] n697_o;
    wire n700_o;
    wire n702_o;
    wire [7:0] n703_o;
    wire [5:0] n705_o;
    wire [5:0] n707_o;
    wire n709_o;
    wire n710_o;
    wire [7:0] n711_o;
    wire [5:0] n713_o;
    wire [5:0] n715_o;
    wire n717_o;
    wire n718_o;
    wire [7:0] n719_o;
    wire [7:0] n720_o;
    wire n722_o;
    wire n724_o;
    wire n726_o;
    wire n727_o;
    wire n729_o;
    wire n730_o;
    wire n732_o;
    wire n733_o;
    wire [31:0] n734_o;
    wire n736_o;
    wire [31:0] n737_o;
    wire [31:0] n739_o;
    wire [9:0] n740_o;
    wire [5:0] n743_o;
    wire n745_o;
    wire [2:0] n747_o;
    wire [9:0] n748_o;
    wire n751_o;
    wire [2:0] n752_o;
    wire n754_o;
    wire [5:0] n757_o;
    wire [5:0] n760_o;
    wire n763_o;
    wire n765_o;
    wire [2:0] n767_o;
    wire [39:0] n770_o;
    wire n773_o;
    wire [5:0] n774_o;
    wire [5:0] n776_o;
    wire n778_o;
    wire n779_o;
    wire [2:0] n780_o;
    wire [39:0] n782_o;
    wire n784_o;
    wire [9:0] n785_o;
    wire n787_o;
    wire n789_o;
    wire n791_o;
    wire n793_o;
    wire [39:0] n795_o;
    wire [5:0] n798_o;
    wire n800_o;
    wire [2:0] n802_o;
    wire [39:0] n804_o;
    wire n807_o;
    wire [5:0] n809_o;
    wire [5:0] n811_o;
    wire [5:0] n813_o;
    wire [5:0] n814_o;
    wire n815_o;
    wire n816_o;
    wire [39:0] n818_o;
    wire n820_o;
    wire n822_o;
    wire [31:0] n823_o;
    wire n825_o;
    wire [7:0] n826_o;
    wire [7:0] n827_o;
    wire [7:0] n829_o;
    wire [5:0] n832_o;
    wire [7:0] n833_o;
    wire [7:0] n835_o;
    wire n837_o;
    wire [5:0] n840_o;
    wire [5:0] n843_o;
    wire n846_o;
    wire [7:0] n848_o;
    wire n850_o;
    wire n852_o;
    wire n853_o;
    wire n854_o;
    wire n855_o;
    wire [5:0] n857_o;
    wire n859_o;
    wire n861_o;
    wire [31:0] n862_o;
    wire n864_o;
    wire n865_o;
    wire [2:0] n866_o;
    wire n867_o;
    wire n868_o;
    wire n869_o;
    wire n870_o;
    wire n871_o;
    wire [3:0] n872_o;
    wire [1:0] n873_o;
    wire [5:0] n874_o;
    wire n875_o;
    wire n876_o;
    wire n877_o;
    wire [6:0] n878_o;
    wire [2:0] n879_o;
    wire n880_o;
    wire n881_o;
    wire n882_o;
    wire n883_o;
    wire n884_o;
    wire [3:0] n885_o;
    wire [5:0] n886_o;
    wire [9:0] n887_o;
    wire n888_o;
    wire n889_o;
    wire n890_o;
    wire n891_o;
    wire n892_o;
    wire [10:0] n893_o;
    wire [3:0] n894_o;
    wire [14:0] n895_o;
    wire n896_o;
    wire n897_o;
    wire n898_o;
    wire [15:0] n899_o;
    wire [6:0] n900_o;
    wire [7:0] n901_o;
    wire [2:0] n902_o;
    wire n903_o;
    wire n904_o;
    wire n905_o;
    wire n906_o;
    wire [3:0] n907_o;
    wire [5:0] n908_o;
    wire [9:0] n909_o;
    wire n910_o;
    wire n911_o;
    wire n912_o;
    wire n913_o;
    wire [10:0] n914_o;
    wire [3:0] n915_o;
    wire [14:0] n916_o;
    wire n917_o;
    wire n918_o;
    wire [15:0] n919_o;
    wire [31:0] n920_o;
    wire [31:0] n922_o;
    wire [6:0] n923_o;
    wire [5:0] n925_o;
    wire n928_o;
    wire [7:0] n929_o;
    wire [6:0] n930_o;
    wire [15:0] n931_o;
    wire [15:0] n932_o;
    wire [6:0] n934_o;
    wire n936_o;
    wire n938_o;
    wire [31:0] n939_o;
    wire n941_o;
    wire n942_o;
    wire [31:0] n943_o;
    wire n945_o;
    wire n946_o;
    wire n947_o;
    wire n948_o;
    wire n949_o;
    wire [31:0] n950_o;
    wire [31:0] n952_o;
    wire [9:0] n953_o;
    wire [31:0] n954_o;
    wire n956_o;
    wire [5:0] n959_o;
    wire n962_o;
    wire n964_o;
    wire [5:0] n966_o;
    wire [5:0] n968_o;
    wire n970_o;
    wire n973_o;
    wire n974_o;
    wire [9:0] n975_o;
    wire n978_o;
    wire [7:0] n980_o;
    wire [31:0] n981_o;
    wire [31:0] n983_o;
    wire [9:0] n984_o;
    wire [31:0] n985_o;
    wire n987_o;
    wire [5:0] n990_o;
    wire n993_o;
    wire n995_o;
    wire [5:0] n997_o;
    wire [5:0] n998_o;
    wire n999_o;
    wire n1001_o;
    wire n1002_o;
    wire [9:0] n1003_o;
    wire n1005_o;
    wire [7:0] n1007_o;
    wire [31:0] n1008_o;
    wire [31:0] n1010_o;
    wire [9:0] n1011_o;
    wire [5:0] n1012_o;
    wire [5:0] n1014_o;
    wire n1016_o;
    wire n1018_o;
    wire n1019_o;
    wire [9:0] n1020_o;
    wire n1022_o;
    wire [7:0] n1024_o;
    wire [31:0] n1025_o;
    wire [31:0] n1027_o;
    wire [7:0] n1028_o;
    wire [6:0] n1029_o;
    wire [7:0] n1031_o;
    wire [5:0] n1033_o;
    wire [5:0] n1035_o;
    wire n1037_o;
    wire n1039_o;
    wire n1040_o;
    wire [7:0] n1041_o;
    wire [9:0] n1042_o;
    wire n1044_o;
    wire [7:0] n1045_o;
    wire [31:0] n1046_o;
    wire [31:0] n1048_o;
    wire [6:0] n1049_o;
    wire [5:0] n1050_o;
    wire [5:0] n1052_o;
    wire n1054_o;
    wire n1057_o;
    wire n1059_o;
    wire n1060_o;
    wire [7:0] n1061_o;
    wire n1062_o;
    wire n1064_o;
    wire [7:0] n1065_o;
    wire [6:0] n1067_o;
    wire n1069_o;
    wire n1071_o;
    wire n1073_o;
    wire [31:0] n1074_o;
    wire n1076_o;
    wire [7:0] n1077_o;
    wire [31:0] n1078_o;
    wire [39:0] n1080_o;
    wire [5:0] n1083_o;
    wire [5:0] n1086_o;
    wire n1089_o;
    wire [39:0] n1091_o;
    wire n1094_o;
    wire [7:0] n1095_o;
    wire n1097_o;
    wire [7:0] n1099_o;
    wire n1101_o;
    wire n1103_o;
    wire n1104_o;
    wire n1105_o;
    wire [31:0] n1106_o;
    wire n1108_o;
    wire [5:0] n1110_o;
    wire [1:0] n1112_o;
    wire n1114_o;
    wire [2:0] n1116_o;
    wire [5:0] n1117_o;
    wire [1:0] n1118_o;
    wire n1119_o;
    wire [2:0] n1120_o;
    wire [5:0] n1122_o;
    wire [1:0] n1123_o;
    wire n1124_o;
    wire [2:0] n1125_o;
    wire n1127_o;
    wire n1129_o;
    wire [55:0] n1130_o;
    reg [5:0] n1162_o;
    reg [5:0] n1176_o;
    reg [5:0] n1195_o;
    reg n1211_o;
    reg n1231_o;
    reg n1235_o;
    reg n1240_o;
    reg n1243_o;
    reg n1250_o;
    reg [1:0] n1253_o;
    reg n1256_o;
    reg [2:0] n1259_o;
    reg n1262_o;
    reg n1265_o;
    reg [39:0] n1274_o;
    reg n1290_o;
    reg [7:0] n1293_o;
    reg [6:0] n1296_o;
    reg [15:0] n1299_o;
    reg [15:0] n1302_o;
    reg [7:0] n1304_o;
    reg [7:0] n1309_o;
    reg [31:0] n1313_o;
    reg [7:0] n1316_o;
    reg n1320_o;
    reg [9:0] n1328_o;
    reg n1336_o;
    reg [7:0] n1341_o;
    reg n1345_o;
    reg [6:0] n1348_o;
    reg n1350_o;
    reg n1353_o;
    wire n1357_o;
    wire n1360_o;
    wire n1363_o;
    wire n1366_o;
    wire n1369_o;
    wire n1372_o;
    wire n1375_o;
    wire n1378_o;
    wire n1381_o;
    wire n1384_o;
    wire n1387_o;
    wire n1390_o;
    wire n1393_o;
    wire n1396_o;
    wire n1399_o;
    wire n1402_o;
    wire n1405_o;
    wire n1408_o;
    wire n1411_o;
    wire n1414_o;
    wire n1417_o;
    wire n1420_o;
    wire n1423_o;
    wire n1426_o;
    wire n1429_o;
    wire n1432_o;
    wire n1435_o;
    wire n1438_o;
    wire n1441_o;
    wire n1444_o;
    wire n1447_o;
    wire n1450_o;
    wire n1453_o;
    wire n1456_o;
    wire n1459_o;
    wire n1462_o;
    wire n1465_o;
    wire n1468_o;
    wire n1471_o;
    wire n1474_o;
    wire n1477_o;
    wire n1480_o;
    wire n1483_o;
    wire n1486_o;
    wire n1489_o;
    wire n1492_o;
    wire n1495_o;
    wire n1498_o;
    wire n1501_o;
    wire n1504_o;
    wire n1507_o;
    wire n1510_o;
    wire n1513_o;
    wire n1516_o;
    wire n1519_o;
    wire n1522_o;
    wire [55:0] n1523_o;
    reg [7:0] n1525_o;
    reg [5:0] n1526_q;
    reg [5:0] n1527_q;
    reg [5:0] n1528_q;
    reg n1529_q;
    reg n1530_q;
    reg n1531_q;
    reg [1:0] n1532_q;
    reg n1533_q;
    reg [2:0] n1534_q;
    reg n1535_q;
    reg [39:0] n1536_q;
    reg [7:0] n1537_q;
    reg [6:0] n1538_q;
    reg [15:0] n1539_q;
    reg [15:0] n1540_q;
    reg [7:0] n1541_q;
    reg [7:0] n1542_q;
    reg [31:0] n1543_q;
    reg [7:0] n1544_q;
    reg [9:0] n1545_q;
    reg [7:0] n1546_q;
    reg n1547_q;
    reg [6:0] n1548_q;
    reg n1549_q;
    reg n1550_q;
    reg n1551_q;
    reg n1552_q;
    reg n1553_q;
    reg n1554_q;
    reg n1555_q;
    reg [7:0] n1556_q;
    reg n1557_q;
    reg n1558_q;
    reg n1559_q;
    reg n1560_q;
    reg [2:0] n1561_q;
    reg [1:0] n1562_q;
    assign cs = n1553_q;  //(module output)
    assign mosi = n1554_q;  //(module output)
    assign sclk = n1555_q;  //(module output)
    assign dout = n1556_q;  //(module output)
    assign dout_avail = n1557_q;  //(module output)
    assign din_taken = n1558_q;  //(module output)
    assign sd_error = n1559_q;  //(module output)
    assign sd_busy = n1560_q;  //(module output)
    assign sd_error_code = n1561_q;  //(module output)
    assign sd_type = n1562_q;  //(module output)
    assign sd_fsm = n1525_o;  //(module output)
    /* sd_spi.vhd:224:8  */
    always @* state = n1526_q;  // (isignal)
    initial state = 6'b000000;
    /* sd_spi.vhd:224:15  */
    always @* new_state = n1162_o;  // (isignal)
    initial new_state = 6'b000000;
    /* sd_spi.vhd:224:26  */
    always @* return_state = n1527_q;  // (isignal)
    initial return_state = 6'b000000;
    /* sd_spi.vhd:224:40  */
    always @* new_return_state = n1176_o;  // (isignal)
    initial new_return_state = 6'b000000;
    /* sd_spi.vhd:224:58  */
    always @* sr_return_state = n1528_q;  // (isignal)
    initial sr_return_state = 6'b000000;
    /* sd_spi.vhd:224:75  */
    always @* new_sr_return_state = n1195_o;  // (isignal)
    initial new_sr_return_state = 6'b000000;
    /* sd_spi.vhd:225:8  */
    always @* set_return_state = n1211_o;  // (isignal)
    initial set_return_state = 1'b0;
    /* sd_spi.vhd:225:26  */
    always @* set_sr_return_state = n1231_o;  // (isignal)
    initial set_sr_return_state = 1'b0;
    /* sd_spi.vhd:228:8  */
    always @* new_sclk = n1235_o;  // (isignal)
    initial new_sclk = 1'b0;
    /* sd_spi.vhd:229:8  */
    always @* scs = n1529_q;  // (isignal)
    initial scs = 1'b1;
    /* sd_spi.vhd:229:13  */
    always @* new_cs = n1240_o;  // (isignal)
    initial new_cs = 1'b1;
    /* sd_spi.vhd:232:8  */
    always @* set_davail = n1243_o;  // (isignal)
    initial set_davail = 1'b0;
    /* sd_spi.vhd:233:8  */
    always @* sdavail = n1530_q;  // (isignal)
    initial sdavail = 1'b0;
    /* sd_spi.vhd:234:8  */
    always @* transfer_data_out = n1531_q;  // (isignal)
    initial transfer_data_out = 1'b0;
    /* sd_spi.vhd:234:27  */
    always @* new_transfer_data_out = n1250_o;  // (isignal)
    initial new_transfer_data_out = 1'b0;
    /* sd_spi.vhd:235:8  */
    always @* card_type = n1532_q;  // (isignal)
    initial card_type = 2'b00;
    /* sd_spi.vhd:235:19  */
    always @* new_card_type = n1253_o;  // (isignal)
    initial new_card_type = 2'b00;
    /* sd_spi.vhd:236:8  */
    always @* error = n1533_q;  // (isignal)
    initial error = 1'b0;
    /* sd_spi.vhd:236:15  */
    always @* new_error = n1256_o;  // (isignal)
    initial new_error = 1'b0;
    /* sd_spi.vhd:237:8  */
    always @* error_code = n1534_q;  // (isignal)
    initial error_code = 3'b000;
    /* sd_spi.vhd:237:20  */
    always @* new_error_code = n1259_o;  // (isignal)
    initial new_error_code = 3'b000;
    /* sd_spi.vhd:238:8  */
    always @* new_busy = n1262_o;  // (isignal)
    initial new_busy = 1'b1;
    /* sd_spi.vhd:239:8  */
    always @* sdin_taken = n1535_q;  // (isignal)
    initial sdin_taken = 1'b0;
    /* sd_spi.vhd:239:20  */
    always @* new_din_taken = n1265_o;  // (isignal)
    initial new_din_taken = 1'b0;
    /* sd_spi.vhd:242:8  */
    always @* cmd_out = n1536_q;  // (isignal)
    initial cmd_out = 40'b1111111111111111111111111111111111111111;
    /* sd_spi.vhd:242:17  */
    always @* new_cmd_out = n1274_o;  // (isignal)
    initial new_cmd_out = 40'b1111111111111111111111111111111111111111;
    /* sd_spi.vhd:243:8  */
    always @* set_cmd_out = n1290_o;  // (isignal)
    initial set_cmd_out = 1'b0;
    /* sd_spi.vhd:244:8  */
    assign data_in = n1537_q;  // (signal)
    /* sd_spi.vhd:244:17  */
    assign new_data_in = n1293_o;  // (signal)
    /* sd_spi.vhd:245:8  */
    assign new_crc7 = n1296_o;  // (signal)
    /* sd_spi.vhd:245:18  */
    assign crc7 = n1538_q;  // (signal)
    /* sd_spi.vhd:246:8  */
    assign new_in_crc16 = n1299_o;  // (signal)
    /* sd_spi.vhd:246:22  */
    assign in_crc16 = n1539_q;  // (signal)
    /* sd_spi.vhd:247:8  */
    assign new_out_crc16 = n1302_o;  // (signal)
    /* sd_spi.vhd:247:23  */
    assign out_crc16 = n1540_q;  // (signal)
    /* sd_spi.vhd:248:8  */
    assign new_crclow = n1304_o;  // (signal)
    /* sd_spi.vhd:248:20  */
    assign crclow = n1541_q;  // (signal)
    /* sd_spi.vhd:249:8  */
    always @* data_out = n1542_q;  // (isignal)
    initial data_out = 8'b00000000;
    /* sd_spi.vhd:249:18  */
    always @* new_data_out = n1309_o;  // (isignal)
    initial new_data_out = 8'b00000000;
    /* sd_spi.vhd:251:8  */
    assign address = n1543_q;  // (signal)
    /* sd_spi.vhd:251:17  */
    assign new_address = n1313_o;  // (signal)
    /* sd_spi.vhd:252:8  */
    assign wr_erase_count = n1544_q;  // (signal)
    /* sd_spi.vhd:252:24  */
    assign new_wr_erase_count = n1316_o;  // (signal)
    /* sd_spi.vhd:253:8  */
    always @* set_address = n1320_o;  // (isignal)
    initial set_address = 1'b0;
    /* sd_spi.vhd:254:8  */
    always @* byte_counter = n1545_q;  // (isignal)
    initial byte_counter = 10'b0000000000;
    /* sd_spi.vhd:254:22  */
    always @* new_byte_counter = n1328_o;  // (isignal)
    initial new_byte_counter = 10'b0000000000;
    /* sd_spi.vhd:255:8  */
    always @* set_byte_counter = n1336_o;  // (isignal)
    initial set_byte_counter = 1'b0;
    /* sd_spi.vhd:256:8  */
    always @* bit_counter = n1546_q;  // (isignal)
    initial bit_counter = 8'b00000000;
    /* sd_spi.vhd:256:21  */
    always @* new_bit_counter = n1341_o;  // (isignal)
    initial new_bit_counter = 8'b00000000;
    /* sd_spi.vhd:257:8  */
    always @* slow_clock = n1547_q;  // (isignal)
    initial slow_clock = 1'b1;
    /* sd_spi.vhd:257:20  */
    always @* new_slow_clock = n1345_o;  // (isignal)
    initial new_slow_clock = 1'b1;
    /* sd_spi.vhd:258:8  */
    always @* clock_divider = n1548_q;  // (isignal)
    initial clock_divider = 7'b0000000;
    /* sd_spi.vhd:258:23  */
    always @* new_clock_divider = n1348_o;  // (isignal)
    initial new_clock_divider = 7'b0000000;
    /* sd_spi.vhd:259:8  */
    always @* multiple = n1549_q;  // (isignal)
    initial multiple = 1'b0;
    /* sd_spi.vhd:259:18  */
    always @* new_multiple = n1350_o;  // (isignal)
    initial new_multiple = 1'b0;
    /* sd_spi.vhd:260:8  */
    always @* skipfirstr1byte = n1550_q;  // (isignal)
    initial skipfirstr1byte = 1'b0;
    /* sd_spi.vhd:260:25  */
    always @* new_skipfirstr1byte = n1353_o;  // (isignal)
    initial new_skipfirstr1byte = 1'b0;
    /* sd_spi.vhd:261:8  */
    always @* din_latch = n1551_q;  // (isignal)
    initial din_latch = 1'b0;
    /* sd_spi.vhd:262:8  */
    always @* last_din_valid = n1552_q;  // (isignal)
    initial last_din_valid = 1'b0;
    /* sd_spi.vhd:313:33  */
    assign n59_o  = set_return_state ? new_return_state : return_state;
    /* sd_spi.vhd:314:33  */
    assign n60_o  = set_sr_return_state ? new_sr_return_state : sr_return_state;
    /* sd_spi.vhd:315:33  */
    assign n61_o  = set_cmd_out ? new_cmd_out : cmd_out;
    /* sd_spi.vhd:317:33  */
    assign n62_o  = set_address ? new_address : address;
    /* sd_spi.vhd:319:33  */
    assign n63_o  = set_byte_counter ? new_byte_counter : byte_counter;
    /* sd_spi.vhd:335:53  */
    assign n64_o  = new_data_out[7];  // extract
    /* sd_spi.vhd:346:51  */
    assign n65_o  = dout_taken & sdavail;
    /* sd_spi.vhd:346:33  */
    assign n67_o  = n65_o ? 1'b0 : n1557_q;
    /* sd_spi.vhd:346:33  */
    assign n69_o  = n65_o ? 1'b0 : sdavail;
    /* sd_spi.vhd:342:33  */
    assign n70_o  = set_davail ? data_in : n1556_q;
    /* sd_spi.vhd:342:33  */
    assign n72_o  = set_davail ? 1'b1 : n67_o;
    /* sd_spi.vhd:342:33  */
    assign n74_o  = set_davail ? 1'b1 : n69_o;
    /* sd_spi.vhd:354:45  */
    assign n75_o  = ~din_valid;
    /* sd_spi.vhd:354:56  */
    assign n76_o  = ~wr;
    /* sd_spi.vhd:354:76  */
    assign n77_o  = ~wr_multiple;
    /* sd_spi.vhd:354:61  */
    assign n78_o  = n77_o & n76_o;
    /* sd_spi.vhd:354:50  */
    assign n79_o  = n75_o | n78_o;
    /* sd_spi.vhd:359:71  */
    assign n80_o  = ~last_din_valid;
    /* sd_spi.vhd:359:53  */
    assign n81_o  = n80_o & din_valid;
    /* sd_spi.vhd:364:49  */
    assign n82_o  = new_din_taken & din_latch;
    /* sd_spi.vhd:364:33  */
    assign n84_o  = n82_o ? 1'b1 : n1558_q;
    /* sd_spi.vhd:364:33  */
    assign n86_o  = n82_o ? 1'b1 : sdin_taken;
    /* sd_spi.vhd:364:33  */
    assign n88_o  = n82_o ? 1'b0 : din_latch;
    /* sd_spi.vhd:359:33  */
    assign n90_o  = n81_o ? 1'b0 : n84_o;
    /* sd_spi.vhd:359:33  */
    assign n92_o  = n81_o ? 1'b0 : n86_o;
    /* sd_spi.vhd:359:33  */
    assign n94_o  = n81_o ? 1'b1 : n88_o;
    /* sd_spi.vhd:354:33  */
    assign n96_o  = n79_o ? 1'b0 : n90_o;
    /* sd_spi.vhd:354:33  */
    assign n98_o  = n79_o ? 1'b0 : n92_o;
    /* sd_spi.vhd:354:33  */
    assign n100_o = n79_o ? 1'b0 : n94_o;
    /* sd_spi.vhd:270:25  */
    assign n102_o = reset ? 1'b1 : new_cs;
    /* sd_spi.vhd:270:25  */
    assign n104_o = reset ? 1'b1 : n64_o;
    /* sd_spi.vhd:270:25  */
    assign n106_o = reset ? 1'b0 : new_sclk;
    /* sd_spi.vhd:270:25  */
    assign n108_o = reset ? 8'b00000000 : n70_o;
    /* sd_spi.vhd:270:25  */
    assign n110_o = reset ? 1'b0 : n72_o;
    /* sd_spi.vhd:270:25  */
    assign n112_o = reset ? 1'b0 : n96_o;
    /* sd_spi.vhd:270:25  */
    assign n114_o = reset ? 1'b1 : new_error;
    /* sd_spi.vhd:270:25  */
    assign n116_o = reset ? 1'b1 : new_busy;
    /* sd_spi.vhd:270:25  */
    assign n118_o = reset ? 3'b111 : new_error_code;
    /* sd_spi.vhd:270:25  */
    assign n120_o = reset ? 2'b00 : new_card_type;
    /* sd_spi.vhd:270:25  */
    assign n122_o = reset ? 6'b000000 : new_state;
    /* sd_spi.vhd:270:25  */
    assign n124_o = reset ? 6'b000000 : n59_o;
    /* sd_spi.vhd:270:25  */
    assign n126_o = reset ? 6'b000000 : n60_o;
    /* sd_spi.vhd:270:25  */
    assign n128_o = reset ? 1'b1 : new_cs;
    /* sd_spi.vhd:270:25  */
    assign n130_o = reset ? 1'b0 : n74_o;
    /* sd_spi.vhd:270:25  */
    assign n132_o = reset ? 1'b0 : new_transfer_data_out;
    /* sd_spi.vhd:270:25  */
    assign n134_o = reset ? 2'b00 : new_card_type;
    /* sd_spi.vhd:270:25  */
    assign n136_o = reset ? 1'b0 : new_error;
    /* sd_spi.vhd:270:25  */
    assign n138_o = reset ? 3'b111 : new_error_code;
    /* sd_spi.vhd:270:25  */
    assign n140_o = reset ? 1'b0 : n98_o;
    /* sd_spi.vhd:270:25  */
    assign n142_o = reset ? 40'b1111111111111111111111111111111111111111 : n61_o;
    /* sd_spi.vhd:270:25  */
    assign n144_o = reset ? 8'b00000000 : new_data_in;
    /* sd_spi.vhd:270:25  */
    assign n146_o = reset ? 7'b0000000 : new_crc7;
    /* sd_spi.vhd:270:25  */
    assign n148_o = reset ? 16'b0000000000000000 : new_in_crc16;
    /* sd_spi.vhd:270:25  */
    assign n150_o = reset ? 16'b0000000000000000 : new_out_crc16;
    /* sd_spi.vhd:270:25  */
    assign n152_o = reset ? 8'b00000000 : new_crclow;
    /* sd_spi.vhd:270:25  */
    assign n154_o = reset ? 8'b11111111 : new_data_out;
    /* sd_spi.vhd:270:25  */
    assign n156_o = reset ? 32'b00000000000000000000000000000000 : n62_o;
    /* sd_spi.vhd:270:25  */
    assign n158_o = reset ? 8'b00000001 : new_wr_erase_count;
    /* sd_spi.vhd:270:25  */
    assign n160_o = reset ? 10'b0000000000 : n63_o;
    /* sd_spi.vhd:270:25  */
    assign n162_o = reset ? 8'b00000000 : new_bit_counter;
    /* sd_spi.vhd:270:25  */
    assign n164_o = reset ? 1'b1 : new_slow_clock;
    /* sd_spi.vhd:270:25  */
    assign n166_o = reset ? 7'b0000000 : new_clock_divider;
    /* sd_spi.vhd:270:25  */
    assign n168_o = reset ? 1'b0 : new_multiple;
    /* sd_spi.vhd:270:25  */
    assign n170_o = reset ? 1'b0 : new_skipfirstr1byte;
    /* sd_spi.vhd:270:25  */
    assign n171_o = reset ? din_latch : n100_o;
    /* sd_spi.vhd:270:25  */
    assign n172_o = reset ? last_din_valid : din_valid;
    /* sd_spi.vhd:389:17  */
    //always @* if (!1'b1) $fatal(1, "assertion failure n213");
    /* sd_spi.vhd:425:17  */
    assign n215_o = state == 6'b000000;
    /* sd_spi.vhd:441:25  */
    assign n217_o = card_present ? 6'b100001 : state;
    /* sd_spi.vhd:431:17  */
    assign n219_o = state == 6'b000001;
    /* sd_spi.vhd:447:40  */
    assign n220_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:447:40  */
    assign n222_o = n220_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:447:25  */
    assign n225_o = n222_o ? 6'b000011 : 6'b100001;
    /* sd_spi.vhd:446:17  */
    assign n227_o = state == 6'b000010;
    /* sd_spi.vhd:453:17  */
    assign n229_o = state == 6'b000011;
    /* sd_spi.vhd:463:35  */
    assign n231_o = data_in == 8'b00000001;
    /* sd_spi.vhd:463:25  */
    assign n234_o = n231_o ? 6'b100011 : 6'b000001;
    /* sd_spi.vhd:463:25  */
    assign n237_o = n231_o ? 6'b000101 : 6'b000000;
    /* sd_spi.vhd:463:25  */
    assign n240_o = n231_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:463:25  */
    assign n242_o = n231_o ? card_type : 2'b00;
    /* sd_spi.vhd:463:25  */
    assign n244_o = n231_o ? error : 1'b1;
    /* sd_spi.vhd:463:25  */
    assign n246_o = n231_o ? error_code : 3'b001;
    /* sd_spi.vhd:463:25  */
    assign n249_o = n231_o ? 40'b0100100000000000000000000000000110101010 : 40'bX;
    /* sd_spi.vhd:463:25  */
    assign n252_o = n231_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:461:17  */
    assign n254_o = state == 6'b000100;
    /* sd_spi.vhd:476:35  */
    assign n255_o = data_in[2];  // extract
    /* sd_spi.vhd:476:25  */
    assign n258_o = n255_o ? 6'b001010 : 6'b100001;
    /* sd_spi.vhd:476:25  */
    assign n261_o = n255_o ? 6'b000000 : 6'b000110;
    /* sd_spi.vhd:476:25  */
    assign n264_o = n255_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:476:25  */
    assign n267_o = n255_o ? 2'b01 : 2'b10;
    /* sd_spi.vhd:474:17  */
    assign n269_o = state == 6'b000101;
    /* sd_spi.vhd:485:17  */
    assign n271_o = state == 6'b000110;
    /* sd_spi.vhd:490:17  */
    assign n273_o = state == 6'b000111;
    /* sd_spi.vhd:495:17  */
    assign n280_o = state == 6'b001000;
    /* sd_spi.vhd:508:36  */
    assign n282_o = data_in == 8'b10101010;
    /* sd_spi.vhd:508:25  */
    assign n285_o = n282_o ? 6'b001010 : 6'b000000;
    /* sd_spi.vhd:505:17  */
    assign n287_o = state == 6'b001001;
    /* sd_spi.vhd:514:17  */
    assign n289_o = state == 6'b001010;
    /* sd_spi.vhd:523:37  */
    assign n291_o = card_type == 2'b01;
    /* sd_spi.vhd:523:25  */
    assign n294_o = n291_o ? 40'b0110100100000000000000000000000000000000 : 40'b0110100101000000000000000000000000000000;
    /* sd_spi.vhd:520:17  */
    assign n296_o = state == 6'b001011;
    /* sd_spi.vhd:533:36  */
    assign n297_o = data_in[0];  // extract
    /* sd_spi.vhd:533:46  */
    assign n298_o = ~n297_o;
    /* sd_spi.vhd:534:46  */
    assign n300_o = card_type == 2'b01;
    /* sd_spi.vhd:534:33  */
    assign n303_o = n300_o ? 6'b010010 : 6'b001101;
    /* sd_spi.vhd:533:25  */
    assign n305_o = n298_o ? n303_o : 6'b001010;
    /* sd_spi.vhd:531:17  */
    assign n307_o = state == 6'b001100;
    /* sd_spi.vhd:543:17  */
    assign n309_o = state == 6'b001101;
    /* sd_spi.vhd:551:35  */
    assign n310_o = data_in[2];  // extract
    /* sd_spi.vhd:551:25  */
    assign n313_o = n310_o ? 6'b000001 : 6'b100001;
    /* sd_spi.vhd:551:25  */
    assign n316_o = n310_o ? 6'b000000 : 6'b001111;
    /* sd_spi.vhd:551:25  */
    assign n319_o = n310_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:551:25  */
    assign n321_o = n310_o ? 2'b00 : card_type;
    /* sd_spi.vhd:551:25  */
    assign n323_o = n310_o ? 1'b1 : error;
    /* sd_spi.vhd:551:25  */
    assign n325_o = n310_o ? 3'b110 : error_code;
    /* sd_spi.vhd:549:17  */
    assign n327_o = state == 6'b001110;
    /* sd_spi.vhd:566:36  */
    assign n328_o = data_in[6];  // extract
    /* sd_spi.vhd:566:25  */
    assign n330_o = n328_o ? 2'b11 : card_type;
    /* sd_spi.vhd:563:17  */
    assign n332_o = state == 6'b001111;
    /* sd_spi.vhd:573:17  */
    assign n334_o = state == 6'b010000;
    /* sd_spi.vhd:578:17  */
    assign n336_o = state == 6'b010001;
    /* sd_spi.vhd:583:17  */
    assign n338_o = state == 6'b010010;
    /* sd_spi.vhd:591:35  */
    assign n340_o = data_in != 8'b00000000;
    /* sd_spi.vhd:591:25  */
    assign n342_o = n340_o ? 6'b000000 : state;
    /* sd_spi.vhd:595:31  */
    assign n343_o = ~rd;
    /* sd_spi.vhd:595:44  */
    assign n344_o = ~wr;
    /* sd_spi.vhd:595:37  */
    assign n345_o = n344_o & n343_o;
    /* sd_spi.vhd:595:66  */
    assign n346_o = ~rd_multiple;
    /* sd_spi.vhd:595:50  */
    assign n347_o = n346_o & n345_o;
    /* sd_spi.vhd:595:88  */
    assign n348_o = ~wr_multiple;
    /* sd_spi.vhd:595:72  */
    assign n349_o = n348_o & n347_o;
    /* sd_spi.vhd:595:25  */
    assign n351_o = n349_o ? 6'b010100 : n342_o;
    /* sd_spi.vhd:595:25  */
    assign n353_o = n349_o ? 1'b0 : error;
    /* sd_spi.vhd:595:25  */
    assign n355_o = n349_o ? 3'b000 : error_code;
    /* sd_spi.vhd:589:17  */
    assign n357_o = state == 6'b010011;
    /* sd_spi.vhd:601:17  */
    assign n359_o = state == 6'b010100;
    /* sd_spi.vhd:612:40  */
    assign n360_o = ~card_present;
    /* sd_spi.vhd:615:38  */
    assign n362_o = data_in == 8'b00000000;
    /* sd_spi.vhd:634:38  */
    assign n363_o = wr | wr_multiple;
    /* sd_spi.vhd:636:51  */
    assign n364_o = ~card_write_prot;
    /* sd_spi.vhd:641:41  */
    assign n366_o = wr ? 8'b00000001 : erase_count;
    /* sd_spi.vhd:641:41  */
    assign n369_o = wr ? 1'b0 : 1'b1;
    /* sd_spi.vhd:634:25  */
    assign n371_o = n387_o ? 6'b101001 : state;
    /* sd_spi.vhd:636:33  */
    assign n373_o = n364_o ? 1'b0 : scs;
    /* sd_spi.vhd:636:33  */
    assign n376_o = n364_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:636:33  */
    assign n379_o = n364_o ? 3'b000 : 3'b101;
    /* sd_spi.vhd:636:33  */
    assign n381_o = n364_o ? addr : 32'bX;
    /* sd_spi.vhd:634:25  */
    assign n382_o = n397_o ? n366_o : wr_erase_count;
    /* sd_spi.vhd:636:33  */
    assign n385_o = n364_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:634:25  */
    assign n386_o = n400_o ? n369_o : multiple;
    /* sd_spi.vhd:634:25  */
    assign n387_o = n364_o & n363_o;
    /* sd_spi.vhd:634:25  */
    assign n389_o = n363_o ? n373_o : 1'b1;
    /* sd_spi.vhd:634:25  */
    assign n390_o = n363_o ? n376_o : error;
    /* sd_spi.vhd:634:25  */
    assign n391_o = n363_o ? n379_o : error_code;
    /* sd_spi.vhd:634:25  */
    assign n394_o = n363_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:634:25  */
    assign n396_o = n363_o ? n381_o : 32'bX;
    /* sd_spi.vhd:634:25  */
    assign n397_o = n364_o & n363_o;
    /* sd_spi.vhd:634:25  */
    assign n399_o = n363_o ? n385_o : 1'b0;
    /* sd_spi.vhd:634:25  */
    assign n400_o = n364_o & n363_o;
    /* sd_spi.vhd:626:25  */
    assign n402_o = rd_multiple ? 6'b010111 : n371_o;
    /* sd_spi.vhd:626:25  */
    assign n404_o = rd_multiple ? 1'b0 : n389_o;
    /* sd_spi.vhd:626:25  */
    assign n406_o = rd_multiple ? 1'b0 : n390_o;
    /* sd_spi.vhd:626:25  */
    assign n408_o = rd_multiple ? 3'b000 : n391_o;
    /* sd_spi.vhd:626:25  */
    assign n410_o = rd_multiple ? 1'b1 : n394_o;
    /* sd_spi.vhd:626:25  */
    assign n411_o = rd_multiple ? addr : n396_o;
    /* sd_spi.vhd:626:25  */
    assign n412_o = rd_multiple ? wr_erase_count : n382_o;
    /* sd_spi.vhd:626:25  */
    assign n414_o = rd_multiple ? 1'b1 : n399_o;
    /* sd_spi.vhd:626:25  */
    assign n416_o = rd_multiple ? 1'b1 : n386_o;
    /* sd_spi.vhd:618:25  */
    assign n418_o = rd ? 6'b010110 : n402_o;
    /* sd_spi.vhd:618:25  */
    assign n420_o = rd ? 1'b0 : n404_o;
    /* sd_spi.vhd:618:25  */
    assign n422_o = rd ? 1'b0 : n406_o;
    /* sd_spi.vhd:618:25  */
    assign n424_o = rd ? 3'b000 : n408_o;
    /* sd_spi.vhd:618:25  */
    assign n426_o = rd ? 1'b1 : n410_o;
    /* sd_spi.vhd:618:25  */
    assign n427_o = rd ? addr : n411_o;
    /* sd_spi.vhd:618:25  */
    assign n428_o = rd ? wr_erase_count : n412_o;
    /* sd_spi.vhd:618:25  */
    assign n430_o = rd ? 1'b1 : n414_o;
    /* sd_spi.vhd:618:25  */
    assign n432_o = rd ? 1'b0 : n416_o;
    /* sd_spi.vhd:615:25  */
    assign n434_o = n362_o ? 6'b010100 : n418_o;
    /* sd_spi.vhd:615:25  */
    assign n435_o = n362_o ? scs : n420_o;
    /* sd_spi.vhd:615:25  */
    assign n436_o = n362_o ? error : n422_o;
    /* sd_spi.vhd:615:25  */
    assign n437_o = n362_o ? error_code : n424_o;
    /* sd_spi.vhd:615:25  */
    assign n439_o = n362_o ? 1'b1 : n426_o;
    /* sd_spi.vhd:615:25  */
    assign n441_o = n362_o ? 32'bX : n427_o;
    /* sd_spi.vhd:615:25  */
    assign n442_o = n362_o ? wr_erase_count : n428_o;
    /* sd_spi.vhd:615:25  */
    assign n444_o = n362_o ? 1'b0 : n430_o;
    /* sd_spi.vhd:615:25  */
    assign n445_o = n362_o ? multiple : n432_o;
    /* sd_spi.vhd:612:25  */
    assign n447_o = n360_o ? 6'b000000 : n434_o;
    /* sd_spi.vhd:612:25  */
    assign n448_o = n360_o ? scs : n435_o;
    /* sd_spi.vhd:612:25  */
    assign n449_o = n360_o ? error : n436_o;
    /* sd_spi.vhd:612:25  */
    assign n450_o = n360_o ? error_code : n437_o;
    /* sd_spi.vhd:612:25  */
    assign n452_o = n360_o ? 1'b1 : n439_o;
    /* sd_spi.vhd:612:25  */
    assign n454_o = n360_o ? 32'bX : n441_o;
    /* sd_spi.vhd:612:25  */
    assign n455_o = n360_o ? wr_erase_count : n442_o;
    /* sd_spi.vhd:612:25  */
    assign n457_o = n360_o ? 1'b0 : n444_o;
    /* sd_spi.vhd:612:25  */
    assign n458_o = n360_o ? multiple : n445_o;
    /* sd_spi.vhd:610:17  */
    assign n460_o = state == 6'b010101;
    /* sd_spi.vhd:661:37  */
    assign n462_o = card_type == 2'b11;
    /* sd_spi.vhd:663:54  */
    assign n464_o = {8'b01010001, address};
    /* sd_spi.vhd:666:63  */
    assign n465_o = address[22:0];  // extract
    /* sd_spi.vhd:666:54  */
    assign n467_o = {8'b01010001, n465_o};
    /* sd_spi.vhd:666:77  */
    assign n469_o = {n467_o, 9'b000000000};
    /* sd_spi.vhd:661:25  */
    assign n470_o = n462_o ? n464_o : n469_o;
    /* sd_spi.vhd:659:17  */
    assign n472_o = state == 6'b010110;
    /* sd_spi.vhd:674:37  */
    assign n474_o = card_type == 2'b11;
    /* sd_spi.vhd:676:54  */
    assign n476_o = {8'b01010010, address};
    /* sd_spi.vhd:679:63  */
    assign n477_o = address[22:0];  // extract
    /* sd_spi.vhd:679:54  */
    assign n479_o = {8'b01010010, n477_o};
    /* sd_spi.vhd:679:77  */
    assign n481_o = {n479_o, 9'b000000000};
    /* sd_spi.vhd:674:25  */
    assign n482_o = n474_o ? n476_o : n481_o;
    /* sd_spi.vhd:672:17  */
    assign n484_o = state == 6'b010111;
    /* sd_spi.vhd:687:35  */
    assign n486_o = data_in != 8'b00000000;
    /* sd_spi.vhd:687:25  */
    assign n489_o = n486_o ? 6'b011110 : 6'b100001;
    /* sd_spi.vhd:687:25  */
    assign n492_o = n486_o ? 6'b000000 : 6'b011001;
    /* sd_spi.vhd:687:25  */
    assign n495_o = n486_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:687:25  */
    assign n497_o = n486_o ? 1'b1 : error;
    /* sd_spi.vhd:687:25  */
    assign n499_o = n486_o ? 3'b001 : error_code;
    /* sd_spi.vhd:685:17  */
    assign n501_o = state == 6'b011000;
    /* sd_spi.vhd:699:30  */
    assign n502_o = ~rd;
    /* sd_spi.vhd:699:50  */
    assign n503_o = ~rd_multiple;
    /* sd_spi.vhd:699:35  */
    assign n504_o = n503_o & n502_o;
    /* sd_spi.vhd:702:39  */
    assign n506_o = data_in == 8'b11111110;
    /* sd_spi.vhd:707:39  */
    assign n507_o = data_in[7:4];  // extract
    /* sd_spi.vhd:707:51  */
    assign n509_o = n507_o == 4'b0000;
    /* sd_spi.vhd:707:25  */
    assign n512_o = n509_o ? 6'b011110 : 6'b100001;
    /* sd_spi.vhd:707:25  */
    assign n514_o = n509_o ? 1'b1 : error;
    /* sd_spi.vhd:707:25  */
    assign n516_o = n509_o ? 3'b100 : error_code;
    /* sd_spi.vhd:702:25  */
    assign n518_o = n506_o ? 6'b100001 : n512_o;
    /* sd_spi.vhd:702:25  */
    assign n521_o = n506_o ? 6'b011010 : 6'b000000;
    /* sd_spi.vhd:702:25  */
    assign n524_o = n506_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:702:25  */
    assign n526_o = n506_o ? 1'b1 : transfer_data_out;
    /* sd_spi.vhd:702:25  */
    assign n527_o = n506_o ? error : n514_o;
    /* sd_spi.vhd:702:25  */
    assign n528_o = n506_o ? error_code : n516_o;
    /* sd_spi.vhd:702:25  */
    assign n530_o = n506_o ? 10'b1000000000 : byte_counter;
    /* sd_spi.vhd:702:25  */
    assign n533_o = n506_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:699:25  */
    assign n535_o = n504_o ? 6'b011110 : n518_o;
    /* sd_spi.vhd:699:25  */
    assign n537_o = n504_o ? 6'b000000 : n521_o;
    /* sd_spi.vhd:699:25  */
    assign n539_o = n504_o ? 1'b0 : n524_o;
    /* sd_spi.vhd:699:25  */
    assign n540_o = n504_o ? transfer_data_out : n526_o;
    /* sd_spi.vhd:699:25  */
    assign n541_o = n504_o ? error : n527_o;
    /* sd_spi.vhd:699:25  */
    assign n542_o = n504_o ? error_code : n528_o;
    /* sd_spi.vhd:699:25  */
    assign n543_o = n504_o ? byte_counter : n530_o;
    /* sd_spi.vhd:699:25  */
    assign n545_o = n504_o ? 1'b0 : n533_o;
    /* sd_spi.vhd:696:17  */
    assign n547_o = state == 6'b011001;
    /* sd_spi.vhd:719:30  */
    assign n548_o = ~rd;
    /* sd_spi.vhd:719:50  */
    assign n549_o = ~rd_multiple;
    /* sd_spi.vhd:719:35  */
    assign n550_o = n549_o & n548_o;
    /* sd_spi.vhd:723:48  */
    assign n551_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:723:48  */
    assign n553_o = n551_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:723:33  */
    assign n556_o = n553_o ? 6'b011100 : 6'b000000;
    /* sd_spi.vhd:723:33  */
    assign n559_o = n553_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:723:33  */
    assign n561_o = n553_o ? 1'b0 : transfer_data_out;
    /* sd_spi.vhd:719:25  */
    assign n564_o = n550_o ? 6'b011011 : 6'b100001;
    /* sd_spi.vhd:719:25  */
    assign n566_o = n550_o ? 6'b000000 : n556_o;
    /* sd_spi.vhd:719:25  */
    assign n568_o = n550_o ? 1'b0 : n559_o;
    /* sd_spi.vhd:719:25  */
    assign n569_o = n550_o ? transfer_data_out : n561_o;
    /* sd_spi.vhd:717:17  */
    assign n571_o = state == 6'b011010;
    /* sd_spi.vhd:737:44  */
    assign n572_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:737:44  */
    assign n574_o = n572_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:737:25  */
    assign n577_o = n574_o ? 6'b011100 : 6'b011011;
    /* sd_spi.vhd:734:25  */
    assign n580_o = multiple ? 6'b011111 : 6'b100001;
    /* sd_spi.vhd:734:25  */
    assign n582_o = multiple ? 6'b000000 : n577_o;
    /* sd_spi.vhd:734:25  */
    assign n585_o = multiple ? 1'b0 : 1'b1;
    /* sd_spi.vhd:731:17  */
    assign n587_o = state == 6'b011011;
    /* sd_spi.vhd:747:17  */
    assign n589_o = state == 6'b011100;
    /* sd_spi.vhd:754:36  */
    assign n591_o = in_crc16 != 16'b0000000000000000;
    /* sd_spi.vhd:758:40  */
    assign n592_o = rd_multiple & multiple;
    /* sd_spi.vhd:758:25  */
    assign n595_o = n592_o ? 6'b100001 : 6'b011110;
    /* sd_spi.vhd:758:25  */
    assign n598_o = n592_o ? 6'b011001 : 6'b000000;
    /* sd_spi.vhd:758:25  */
    assign n601_o = n592_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:754:25  */
    assign n603_o = n591_o ? 6'b011110 : n595_o;
    /* sd_spi.vhd:754:25  */
    assign n605_o = n591_o ? 6'b000000 : n598_o;
    /* sd_spi.vhd:754:25  */
    assign n607_o = n591_o ? 1'b0 : n601_o;
    /* sd_spi.vhd:754:25  */
    assign n609_o = n591_o ? 1'b1 : error;
    /* sd_spi.vhd:754:25  */
    assign n611_o = n591_o ? 3'b010 : error_code;
    /* sd_spi.vhd:752:17  */
    assign n613_o = state == 6'b011101;
    /* sd_spi.vhd:770:31  */
    assign n614_o = ~rd;
    /* sd_spi.vhd:770:53  */
    assign n615_o = ~rd_multiple;
    /* sd_spi.vhd:770:37  */
    assign n616_o = n615_o & n614_o;
    /* sd_spi.vhd:771:33  */
    assign n619_o = multiple ? 6'b011111 : 6'b010100;
    /* sd_spi.vhd:770:25  */
    assign n620_o = n616_o ? n619_o : state;
    /* sd_spi.vhd:767:17  */
    assign n622_o = state == 6'b011110;
    /* sd_spi.vhd:778:17  */
    assign n624_o = state == 6'b011111;
    /* sd_spi.vhd:787:35  */
    assign n626_o = data_in != 8'b00000000;
    /* sd_spi.vhd:790:47  */
    assign n627_o = ~rd_multiple;
    /* sd_spi.vhd:790:33  */
    assign n629_o = n627_o ? 6'b010100 : state;
    /* sd_spi.vhd:787:25  */
    assign n631_o = n626_o ? 6'b000000 : n629_o;
    /* sd_spi.vhd:785:17  */
    assign n633_o = state == 6'b100000;
    /* sd_spi.vhd:795:17  */
    assign n635_o = state == 6'b101001;
    /* sd_spi.vhd:803:52  */
    assign n637_o = {32'b01010111000000000000000000000000, wr_erase_count};
    /* sd_spi.vhd:804:25  */
    assign n640_o = wr ? 6'b101011 : 6'b101100;
    /* sd_spi.vhd:801:17  */
    assign n642_o = state == 6'b101010;
    /* sd_spi.vhd:815:38  */
    assign n644_o = card_type == 2'b11;
    /* sd_spi.vhd:816:54  */
    assign n646_o = {8'b01011000, address};
    /* sd_spi.vhd:818:63  */
    assign n647_o = address[22:0];  // extract
    /* sd_spi.vhd:818:54  */
    assign n649_o = {8'b01011000, n647_o};
    /* sd_spi.vhd:818:77  */
    assign n651_o = {n649_o, 9'b000000000};
    /* sd_spi.vhd:815:25  */
    assign n652_o = n644_o ? n646_o : n651_o;
    /* sd_spi.vhd:813:17  */
    assign n654_o = state == 6'b101011;
    /* sd_spi.vhd:826:38  */
    assign n656_o = card_type == 2'b11;
    /* sd_spi.vhd:827:54  */
    assign n658_o = {8'b01011001, address};
    /* sd_spi.vhd:829:63  */
    assign n659_o = address[22:0];  // extract
    /* sd_spi.vhd:829:54  */
    assign n661_o = {8'b01011001, n659_o};
    /* sd_spi.vhd:829:77  */
    assign n663_o = {n661_o, 9'b000000000};
    /* sd_spi.vhd:826:25  */
    assign n664_o = n656_o ? n658_o : n663_o;
    /* sd_spi.vhd:824:17  */
    assign n666_o = state == 6'b101100;
    /* sd_spi.vhd:837:35  */
    assign n668_o = data_in != 8'b00000000;
    /* sd_spi.vhd:837:25  */
    assign n671_o = n668_o ? 6'b110111 : 6'b101110;
    /* sd_spi.vhd:837:25  */
    assign n673_o = n668_o ? 1'b1 : error;
    /* sd_spi.vhd:837:25  */
    assign n675_o = n668_o ? 3'b001 : error_code;
    /* sd_spi.vhd:835:17  */
    assign n677_o = state == 6'b101101;
    /* sd_spi.vhd:847:25  */
    assign n680_o = multiple ? 8'b11111100 : 8'b11111110;
    /* sd_spi.vhd:845:17  */
    assign n682_o = state == 6'b101110;
    /* sd_spi.vhd:855:17  */
    assign n684_o = state == 6'b101111;
    /* sd_spi.vhd:863:41  */
    assign n685_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:863:41  */
    assign n687_o = n685_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:864:58  */
    assign n688_o = out_crc16[15:8];  // extract
    /* sd_spi.vhd:865:56  */
    assign n689_o = out_crc16[7:0];  // extract
    /* sd_spi.vhd:868:33  */
    assign n690_o = ~wr;
    /* sd_spi.vhd:868:53  */
    assign n691_o = ~wr_multiple;
    /* sd_spi.vhd:868:38  */
    assign n692_o = n691_o & n690_o;
    /* sd_spi.vhd:871:25  */
    assign n694_o = din_latch ? 6'b100001 : state;
    /* sd_spi.vhd:871:25  */
    assign n697_o = din_latch ? 6'b110000 : 6'b000000;
    /* sd_spi.vhd:871:25  */
    assign n700_o = din_latch ? 1'b1 : 1'b0;
    /* sd_spi.vhd:871:25  */
    assign n702_o = din_latch ? 1'b1 : sdin_taken;
    /* sd_spi.vhd:871:25  */
    assign n703_o = din_latch ? din : data_out;
    /* sd_spi.vhd:868:25  */
    assign n705_o = n692_o ? 6'b110101 : n694_o;
    /* sd_spi.vhd:868:25  */
    assign n707_o = n692_o ? 6'b000000 : n697_o;
    /* sd_spi.vhd:868:25  */
    assign n709_o = n692_o ? 1'b0 : n700_o;
    /* sd_spi.vhd:868:25  */
    assign n710_o = n692_o ? sdin_taken : n702_o;
    /* sd_spi.vhd:868:25  */
    assign n711_o = n692_o ? data_out : n703_o;
    /* sd_spi.vhd:863:25  */
    assign n713_o = n687_o ? 6'b100001 : n705_o;
    /* sd_spi.vhd:863:25  */
    assign n715_o = n687_o ? 6'b110001 : n707_o;
    /* sd_spi.vhd:863:25  */
    assign n717_o = n687_o ? 1'b1 : n709_o;
    /* sd_spi.vhd:863:25  */
    assign n718_o = n687_o ? sdin_taken : n710_o;
    /* sd_spi.vhd:863:25  */
    assign n719_o = n687_o ? n689_o : crclow;
    /* sd_spi.vhd:863:25  */
    assign n720_o = n687_o ? n688_o : n711_o;
    /* sd_spi.vhd:861:17  */
    assign n722_o = state == 6'b110000;
    /* sd_spi.vhd:878:17  */
    assign n724_o = state == 6'b110001;
    /* sd_spi.vhd:884:17  */
    assign n726_o = state == 6'b110010;
    /* sd_spi.vhd:892:36  */
    assign n727_o = data_in[4];  // extract
    /* sd_spi.vhd:892:40  */
    assign n729_o = n727_o != 1'b0;
    /* sd_spi.vhd:892:59  */
    assign n730_o = data_in[0];  // extract
    /* sd_spi.vhd:892:63  */
    assign n732_o = n730_o != 1'b1;
    /* sd_spi.vhd:892:48  */
    assign n733_o = n729_o | n732_o;
    /* sd_spi.vhd:893:48  */
    assign n734_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:893:48  */
    assign n736_o = n734_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:898:74  */
    assign n737_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:898:74  */
    assign n739_o = n737_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:898:61  */
    assign n740_o = n739_o[9:0];  // trunc
    /* sd_spi.vhd:893:33  */
    assign n743_o = n736_o ? 6'b110110 : 6'b100001;
    /* sd_spi.vhd:893:33  */
    assign n745_o = n736_o ? 1'b1 : error;
    /* sd_spi.vhd:893:33  */
    assign n747_o = n736_o ? 3'b001 : error_code;
    /* sd_spi.vhd:893:33  */
    assign n748_o = n736_o ? byte_counter : n740_o;
    /* sd_spi.vhd:893:33  */
    assign n751_o = n736_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:901:38  */
    assign n752_o = data_in[3:1];  // extract
    /* sd_spi.vhd:901:51  */
    assign n754_o = n752_o != 3'b010;
    /* sd_spi.vhd:901:25  */
    assign n757_o = n754_o ? 6'b110110 : 6'b100001;
    /* sd_spi.vhd:901:25  */
    assign n760_o = n754_o ? 6'b000000 : 6'b110100;
    /* sd_spi.vhd:901:25  */
    assign n763_o = n754_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:901:25  */
    assign n765_o = n754_o ? 1'b1 : error;
    /* sd_spi.vhd:901:25  */
    assign n767_o = n754_o ? 3'b011 : error_code;
    /* sd_spi.vhd:901:25  */
    assign n770_o = n754_o ? 40'bX : 40'b0000000000000000000101010010111111010100;
    /* sd_spi.vhd:901:25  */
    assign n773_o = n754_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:892:25  */
    assign n774_o = n733_o ? n743_o : n757_o;
    /* sd_spi.vhd:892:25  */
    assign n776_o = n733_o ? 6'b000000 : n760_o;
    /* sd_spi.vhd:892:25  */
    assign n778_o = n733_o ? 1'b0 : n763_o;
    /* sd_spi.vhd:892:25  */
    assign n779_o = n733_o ? n745_o : n765_o;
    /* sd_spi.vhd:892:25  */
    assign n780_o = n733_o ? n747_o : n767_o;
    /* sd_spi.vhd:892:25  */
    assign n782_o = n733_o ? 40'bX : n770_o;
    /* sd_spi.vhd:892:25  */
    assign n784_o = n733_o ? 1'b0 : n773_o;
    /* sd_spi.vhd:892:25  */
    assign n785_o = n733_o ? n748_o : byte_counter;
    /* sd_spi.vhd:892:25  */
    assign n787_o = n733_o ? n751_o : 1'b0;
    /* sd_spi.vhd:890:17  */
    assign n789_o = state == 6'b110011;
    /* sd_spi.vhd:916:35  */
    assign n791_o = data_in == 8'b00000000;
    /* sd_spi.vhd:917:43  */
    assign n793_o = cmd_out == 40'b0000000000000000000000000000000000000000;
    /* sd_spi.vhd:922:91  */
    assign n795_o = cmd_out - 40'b0000000000000000000000000000000000000001;
    /* sd_spi.vhd:917:33  */
    assign n798_o = n793_o ? 6'b110110 : 6'b100001;
    /* sd_spi.vhd:916:25  */
    assign n800_o = n815_o ? 1'b1 : error;
    /* sd_spi.vhd:916:25  */
    assign n802_o = n816_o ? 3'b010 : error_code;
    /* sd_spi.vhd:917:33  */
    assign n804_o = n793_o ? 40'bX : n795_o;
    /* sd_spi.vhd:917:33  */
    assign n807_o = n793_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:928:49  */
    assign n809_o = din_latch ? 6'b101110 : state;
    /* sd_spi.vhd:927:41  */
    assign n811_o = wr_multiple ? n809_o : 6'b110110;
    /* sd_spi.vhd:926:33  */
    assign n813_o = multiple ? n811_o : 6'b110111;
    /* sd_spi.vhd:916:25  */
    assign n814_o = n791_o ? n798_o : n813_o;
    /* sd_spi.vhd:916:25  */
    assign n815_o = n793_o & n791_o;
    /* sd_spi.vhd:916:25  */
    assign n816_o = n793_o & n791_o;
    /* sd_spi.vhd:916:25  */
    assign n818_o = n791_o ? n804_o : 40'bX;
    /* sd_spi.vhd:916:25  */
    assign n820_o = n791_o ? n807_o : 1'b0;
    /* sd_spi.vhd:914:17  */
    assign n822_o = state == 6'b110100;
    /* sd_spi.vhd:943:40  */
    assign n823_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:943:40  */
    assign n825_o = n823_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:944:58  */
    assign n826_o = out_crc16[15:8];  // extract
    /* sd_spi.vhd:945:56  */
    assign n827_o = out_crc16[7:0];  // extract
    /* sd_spi.vhd:945:69  */
    assign n829_o = n827_o ^ 8'b00000001;
    /* sd_spi.vhd:943:25  */
    assign n832_o = n825_o ? 6'b110001 : 6'b110101;
    /* sd_spi.vhd:943:25  */
    assign n833_o = n825_o ? n829_o : crclow;
    /* sd_spi.vhd:943:25  */
    assign n835_o = n825_o ? n826_o : 8'b00000000;
    /* sd_spi.vhd:941:17  */
    assign n837_o = state == 6'b110101;
    /* sd_spi.vhd:956:25  */
    assign n840_o = multiple ? 6'b100001 : 6'b110111;
    /* sd_spi.vhd:956:25  */
    assign n843_o = multiple ? 6'b110100 : 6'b000000;
    /* sd_spi.vhd:956:25  */
    assign n846_o = multiple ? 1'b1 : 1'b0;
    /* sd_spi.vhd:956:25  */
    assign n848_o = multiple ? 8'b11111101 : data_out;
    /* sd_spi.vhd:956:25  */
    assign n850_o = multiple ? 1'b0 : multiple;
    /* sd_spi.vhd:954:17  */
    assign n852_o = state == 6'b110110;
    /* sd_spi.vhd:967:31  */
    assign n853_o = ~wr;
    /* sd_spi.vhd:967:51  */
    assign n854_o = ~wr_multiple;
    /* sd_spi.vhd:967:36  */
    assign n855_o = n854_o & n853_o;
    /* sd_spi.vhd:967:25  */
    assign n857_o = n855_o ? 6'b010100 : state;
    /* sd_spi.vhd:965:17  */
    assign n859_o = state == 6'b110111;
    /* sd_spi.vhd:985:38  */
    assign n861_o = slow_clock == 1'b0;
    /* sd_spi.vhd:985:61  */
    assign n862_o = {25'b0, clock_divider};  //  uext
    /* sd_spi.vhd:985:61  */
    assign n864_o = n862_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:985:45  */
    assign n865_o = n861_o | n864_o;
    /* sd_spi.vhd:989:49  */
    assign n866_o = crc7[5:3];  // extract
    /* sd_spi.vhd:989:69  */
    assign n867_o = crc7[2];  // extract
    /* sd_spi.vhd:989:81  */
    assign n868_o = crc7[6];  // extract
    /* sd_spi.vhd:989:73  */
    assign n869_o = n867_o ^ n868_o;
    /* sd_spi.vhd:989:97  */
    assign n870_o = data_out[7];  // extract
    /* sd_spi.vhd:989:85  */
    assign n871_o = n869_o ^ n870_o;
    /* sd_spi.vhd:989:62  */
    assign n872_o = {n866_o, n871_o};
    /* sd_spi.vhd:989:108  */
    assign n873_o = crc7[1:0];  // extract
    /* sd_spi.vhd:989:102  */
    assign n874_o = {n872_o, n873_o};
    /* sd_spi.vhd:989:128  */
    assign n875_o = crc7[6];  // extract
    /* sd_spi.vhd:989:144  */
    assign n876_o = data_out[7];  // extract
    /* sd_spi.vhd:989:132  */
    assign n877_o = n875_o ^ n876_o;
    /* sd_spi.vhd:989:121  */
    assign n878_o = {n874_o, n877_o};
    /* sd_spi.vhd:990:59  */
    assign n879_o = out_crc16[14:12];  // extract
    /* sd_spi.vhd:990:85  */
    assign n880_o = data_out[7];  // extract
    /* sd_spi.vhd:990:102  */
    assign n881_o = out_crc16[15];  // extract
    /* sd_spi.vhd:990:89  */
    assign n882_o = n880_o ^ n881_o;
    /* sd_spi.vhd:990:120  */
    assign n883_o = out_crc16[11];  // extract
    /* sd_spi.vhd:990:107  */
    assign n884_o = n882_o ^ n883_o;
    /* sd_spi.vhd:990:74  */
    assign n885_o = {n879_o, n884_o};
    /* sd_spi.vhd:990:137  */
    assign n886_o = out_crc16[10:5];  // extract
    /* sd_spi.vhd:990:126  */
    assign n887_o = {n885_o, n886_o};
    /* sd_spi.vhd:991:42  */
    assign n888_o = data_out[7];  // extract
    /* sd_spi.vhd:991:59  */
    assign n889_o = out_crc16[15];  // extract
    /* sd_spi.vhd:991:46  */
    assign n890_o = n888_o ^ n889_o;
    /* sd_spi.vhd:991:77  */
    assign n891_o = out_crc16[4];  // extract
    /* sd_spi.vhd:991:64  */
    assign n892_o = n890_o ^ n891_o;
    /* sd_spi.vhd:990:151  */
    assign n893_o = {n887_o, n892_o};
    /* sd_spi.vhd:991:93  */
    assign n894_o = out_crc16[3:0];  // extract
    /* sd_spi.vhd:991:82  */
    assign n895_o = {n893_o, n894_o};
    /* sd_spi.vhd:991:117  */
    assign n896_o = data_out[7];  // extract
    /* sd_spi.vhd:991:134  */
    assign n897_o = out_crc16[15];  // extract
    /* sd_spi.vhd:991:121  */
    assign n898_o = n896_o ^ n897_o;
    /* sd_spi.vhd:991:106  */
    assign n899_o = {n895_o, n898_o};
    /* sd_spi.vhd:993:55  */
    assign n900_o = data_in[6:0];  // extract
    /* sd_spi.vhd:993:68  */
    assign n901_o = {n900_o, miso};
    /* sd_spi.vhd:995:57  */
    assign n902_o = in_crc16[14:12];  // extract
    /* sd_spi.vhd:995:92  */
    assign n903_o = in_crc16[15];  // extract
    /* sd_spi.vhd:995:80  */
    assign n904_o = miso ^ n903_o;
    /* sd_spi.vhd:995:109  */
    assign n905_o = in_crc16[11];  // extract
    /* sd_spi.vhd:995:97  */
    assign n906_o = n904_o ^ n905_o;
    /* sd_spi.vhd:995:72  */
    assign n907_o = {n902_o, n906_o};
    /* sd_spi.vhd:995:125  */
    assign n908_o = in_crc16[10:5];  // extract
    /* sd_spi.vhd:995:115  */
    assign n909_o = {n907_o, n908_o};
    /* sd_spi.vhd:996:59  */
    assign n910_o = in_crc16[15];  // extract
    /* sd_spi.vhd:996:47  */
    assign n911_o = miso ^ n910_o;
    /* sd_spi.vhd:996:76  */
    assign n912_o = in_crc16[4];  // extract
    /* sd_spi.vhd:996:64  */
    assign n913_o = n911_o ^ n912_o;
    /* sd_spi.vhd:995:139  */
    assign n914_o = {n909_o, n913_o};
    /* sd_spi.vhd:996:91  */
    assign n915_o = in_crc16[3:0];  // extract
    /* sd_spi.vhd:996:81  */
    assign n916_o = {n914_o, n915_o};
    /* sd_spi.vhd:996:124  */
    assign n917_o = in_crc16[15];  // extract
    /* sd_spi.vhd:996:112  */
    assign n918_o = miso ^ n917_o;
    /* sd_spi.vhd:996:104  */
    assign n919_o = {n916_o, n918_o};
    /* sd_spi.vhd:999:68  */
    assign n920_o = {25'b0, clock_divider};  //  uext
    /* sd_spi.vhd:999:68  */
    assign n922_o = n920_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:999:54  */
    assign n923_o = n922_o[6:0];  // trunc
    /* sd_spi.vhd:985:25  */
    assign n925_o = n865_o ? 6'b100010 : state;
    /* sd_spi.vhd:985:25  */
    assign n928_o = n865_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:985:25  */
    assign n929_o = n865_o ? n901_o : data_in;
    /* sd_spi.vhd:985:25  */
    assign n930_o = n865_o ? n878_o : crc7;
    /* sd_spi.vhd:985:25  */
    assign n931_o = n865_o ? n919_o : in_crc16;
    /* sd_spi.vhd:985:25  */
    assign n932_o = n865_o ? n899_o : out_crc16;
    /* sd_spi.vhd:985:25  */
    assign n934_o = n865_o ? 7'b1000000 : n923_o;
    /* sd_spi.vhd:971:17  */
    assign n936_o = state == 6'b100001;
    /* sd_spi.vhd:1003:38  */
    assign n938_o = slow_clock == 1'b0;
    /* sd_spi.vhd:1003:61  */
    assign n939_o = {25'b0, clock_divider};  //  uext
    /* sd_spi.vhd:1003:61  */
    assign n941_o = n939_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:1003:45  */
    assign n942_o = n938_o | n941_o;
    /* sd_spi.vhd:1005:49  */
    assign n943_o = {24'b0, bit_counter};  //  uext
    /* sd_spi.vhd:1005:49  */
    assign n945_o = n943_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:1008:60  */
    assign n946_o = rd | rd_multiple;
    /* sd_spi.vhd:1009:67  */
    assign n947_o = ~sdavail;
    /* sd_spi.vhd:1009:86  */
    assign n948_o = ~dout_taken;
    /* sd_spi.vhd:1009:72  */
    assign n949_o = n948_o & n947_o;
    /* sd_spi.vhd:1013:98  */
    assign n950_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1013:98  */
    assign n952_o = n950_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1013:85  */
    assign n953_o = n952_o[9:0];  // trunc
    /* sd_spi.vhd:1016:80  */
    assign n954_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1016:80  */
    assign n956_o = n954_o == 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1016:65  */
    assign n959_o = n956_o ? 6'b011100 : 6'b000000;
    /* sd_spi.vhd:1016:65  */
    assign n962_o = n956_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:1009:57  */
    assign n964_o = n974_o ? 1'b0 : transfer_data_out;
    /* sd_spi.vhd:1009:57  */
    assign n966_o = n949_o ? 6'b100001 : state;
    /* sd_spi.vhd:1009:57  */
    assign n968_o = n949_o ? n959_o : 6'b000000;
    /* sd_spi.vhd:1009:57  */
    assign n970_o = n949_o ? n962_o : 1'b0;
    /* sd_spi.vhd:1009:57  */
    assign n973_o = n949_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:1009:57  */
    assign n974_o = n956_o & n949_o;
    /* sd_spi.vhd:1009:57  */
    assign n975_o = n949_o ? n953_o : byte_counter;
    /* sd_spi.vhd:1009:57  */
    assign n978_o = n949_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:1009:57  */
    assign n980_o = n949_o ? 8'b00000111 : bit_counter;
    /* sd_spi.vhd:1025:90  */
    assign n981_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1025:90  */
    assign n983_o = n981_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1025:77  */
    assign n984_o = n983_o[9:0];  // trunc
    /* sd_spi.vhd:1028:72  */
    assign n985_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1028:72  */
    assign n987_o = n985_o == 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1028:57  */
    assign n990_o = n987_o ? 6'b011100 : 6'b000000;
    /* sd_spi.vhd:1028:57  */
    assign n993_o = n987_o ? 1'b1 : 1'b0;
    /* sd_spi.vhd:1028:57  */
    assign n995_o = n987_o ? 1'b0 : transfer_data_out;
    /* sd_spi.vhd:1008:49  */
    assign n997_o = n946_o ? n966_o : 6'b100001;
    /* sd_spi.vhd:1008:49  */
    assign n998_o = n946_o ? n968_o : n990_o;
    /* sd_spi.vhd:1008:49  */
    assign n999_o = n946_o ? n970_o : n993_o;
    /* sd_spi.vhd:1008:49  */
    assign n1001_o = n946_o ? n973_o : 1'b0;
    /* sd_spi.vhd:1008:49  */
    assign n1002_o = n946_o ? n964_o : n995_o;
    /* sd_spi.vhd:1008:49  */
    assign n1003_o = n946_o ? n975_o : n984_o;
    /* sd_spi.vhd:1008:49  */
    assign n1005_o = n946_o ? n978_o : 1'b1;
    /* sd_spi.vhd:1008:49  */
    assign n1007_o = n946_o ? n980_o : 8'b00000111;
    /* sd_spi.vhd:1038:82  */
    assign n1008_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1038:82  */
    assign n1010_o = n1008_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1038:69  */
    assign n1011_o = n1010_o[9:0];  // trunc
    /* sd_spi.vhd:1007:41  */
    assign n1012_o = transfer_data_out ? n997_o : sr_return_state;
    /* sd_spi.vhd:1007:41  */
    assign n1014_o = transfer_data_out ? n998_o : 6'b000000;
    /* sd_spi.vhd:1007:41  */
    assign n1016_o = transfer_data_out ? n999_o : 1'b0;
    /* sd_spi.vhd:1007:41  */
    assign n1018_o = transfer_data_out ? n1001_o : 1'b0;
    /* sd_spi.vhd:1003:25  */
    assign n1019_o = n1060_o ? n1002_o : transfer_data_out;
    /* sd_spi.vhd:1007:41  */
    assign n1020_o = transfer_data_out ? n1003_o : n1011_o;
    /* sd_spi.vhd:1007:41  */
    assign n1022_o = transfer_data_out ? n1005_o : 1'b1;
    /* sd_spi.vhd:1007:41  */
    assign n1024_o = transfer_data_out ? n1007_o : 8'b00000111;
    /* sd_spi.vhd:1041:72  */
    assign n1025_o = {24'b0, bit_counter};  //  uext
    /* sd_spi.vhd:1041:72  */
    assign n1027_o = n1025_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1041:60  */
    assign n1028_o = n1027_o[7:0];  // trunc
    /* sd_spi.vhd:1042:65  */
    assign n1029_o = data_out[6:0];  // extract
    /* sd_spi.vhd:1042:78  */
    assign n1031_o = {n1029_o, 1'b1};
    /* sd_spi.vhd:1005:33  */
    assign n1033_o = n945_o ? n1012_o : 6'b100001;
    /* sd_spi.vhd:1005:33  */
    assign n1035_o = n945_o ? n1014_o : 6'b000000;
    /* sd_spi.vhd:1005:33  */
    assign n1037_o = n945_o ? n1016_o : 1'b0;
    /* sd_spi.vhd:1005:33  */
    assign n1039_o = n945_o ? n1018_o : 1'b0;
    /* sd_spi.vhd:1005:33  */
    assign n1040_o = transfer_data_out & n945_o;
    /* sd_spi.vhd:1005:33  */
    assign n1041_o = n945_o ? data_out : n1031_o;
    /* sd_spi.vhd:1003:25  */
    assign n1042_o = n1062_o ? n1020_o : byte_counter;
    /* sd_spi.vhd:1005:33  */
    assign n1044_o = n945_o ? n1022_o : 1'b0;
    /* sd_spi.vhd:1005:33  */
    assign n1045_o = n945_o ? n1024_o : n1028_o;
    /* sd_spi.vhd:1047:68  */
    assign n1046_o = {25'b0, clock_divider};  //  uext
    /* sd_spi.vhd:1047:68  */
    assign n1048_o = n1046_o - 32'b00000000000000000000000000000001;
    /* sd_spi.vhd:1047:54  */
    assign n1049_o = n1048_o[6:0];  // trunc
    /* sd_spi.vhd:1003:25  */
    assign n1050_o = n942_o ? n1033_o : state;
    /* sd_spi.vhd:1003:25  */
    assign n1052_o = n942_o ? n1035_o : 6'b000000;
    /* sd_spi.vhd:1003:25  */
    assign n1054_o = n942_o ? n1037_o : 1'b0;
    /* sd_spi.vhd:1003:25  */
    assign n1057_o = n942_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:1003:25  */
    assign n1059_o = n942_o ? n1039_o : 1'b0;
    /* sd_spi.vhd:1003:25  */
    assign n1060_o = n1040_o & n942_o;
    /* sd_spi.vhd:1003:25  */
    assign n1061_o = n942_o ? n1041_o : data_out;
    /* sd_spi.vhd:1003:25  */
    assign n1062_o = n945_o & n942_o;
    /* sd_spi.vhd:1003:25  */
    assign n1064_o = n942_o ? n1044_o : 1'b0;
    /* sd_spi.vhd:1003:25  */
    assign n1065_o = n942_o ? n1045_o : bit_counter;
    /* sd_spi.vhd:1003:25  */
    assign n1067_o = n942_o ? 7'b1000000 : n1049_o;
    /* sd_spi.vhd:1002:17  */
    assign n1069_o = state == 6'b100010;
    /* sd_spi.vhd:1050:17  */
    assign n1071_o = state == 6'b100011;
    /* sd_spi.vhd:1057:17  */
    assign n1073_o = state == 6'b100100;
    /* sd_spi.vhd:1065:40  */
    assign n1074_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1065:40  */
    assign n1076_o = n1074_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:1068:56  */
    assign n1077_o = cmd_out[39:32];  // extract
    /* sd_spi.vhd:1069:55  */
    assign n1078_o = cmd_out[31:0];  // extract
    /* sd_spi.vhd:1069:69  */
    assign n1080_o = {n1078_o, 8'b11111111};
    /* sd_spi.vhd:1065:25  */
    assign n1083_o = n1076_o ? 6'b100110 : 6'b100001;
    /* sd_spi.vhd:1065:25  */
    assign n1086_o = n1076_o ? 6'b000000 : 6'b100101;
    /* sd_spi.vhd:1065:25  */
    assign n1089_o = n1076_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:1065:25  */
    assign n1091_o = n1076_o ? 40'bX : n1080_o;
    /* sd_spi.vhd:1065:25  */
    assign n1094_o = n1076_o ? 1'b0 : 1'b1;
    /* sd_spi.vhd:1065:25  */
    assign n1095_o = n1076_o ? data_out : n1077_o;
    /* sd_spi.vhd:1063:17  */
    assign n1097_o = state == 6'b100101;
    /* sd_spi.vhd:1076:46  */
    assign n1099_o = {crc7, 1'b1};
    /* sd_spi.vhd:1074:17  */
    assign n1101_o = state == 6'b100110;
    /* sd_spi.vhd:1080:17  */
    assign n1103_o = state == 6'b100111;
    /* sd_spi.vhd:1092:38  */
    assign n1104_o = data_in[7];  // extract
    /* sd_spi.vhd:1092:47  */
    assign n1105_o = ~n1104_o;
    /* sd_spi.vhd:1095:48  */
    assign n1106_o = {22'b0, byte_counter};  //  uext
    /* sd_spi.vhd:1095:48  */
    assign n1108_o = n1106_o == 32'b00000000000000000000000000000000;
    /* sd_spi.vhd:1095:33  */
    assign n1110_o = n1108_o ? state : 6'b100001;
    /* sd_spi.vhd:1095:33  */
    assign n1112_o = n1108_o ? 2'b00 : card_type;
    /* sd_spi.vhd:1095:33  */
    assign n1114_o = n1108_o ? 1'b1 : error;
    /* sd_spi.vhd:1095:33  */
    assign n1116_o = n1108_o ? 3'b111 : error_code;
    /* sd_spi.vhd:1092:25  */
    assign n1117_o = n1105_o ? return_state : n1110_o;
    /* sd_spi.vhd:1092:25  */
    assign n1118_o = n1105_o ? card_type : n1112_o;
    /* sd_spi.vhd:1092:25  */
    assign n1119_o = n1105_o ? error : n1114_o;
    /* sd_spi.vhd:1092:25  */
    assign n1120_o = n1105_o ? error_code : n1116_o;
    /* sd_spi.vhd:1088:25  */
    assign n1122_o = skipfirstr1byte ? 6'b100001 : n1117_o;
    /* sd_spi.vhd:1088:25  */
    assign n1123_o = skipfirstr1byte ? card_type : n1118_o;
    /* sd_spi.vhd:1088:25  */
    assign n1124_o = skipfirstr1byte ? error : n1119_o;
    /* sd_spi.vhd:1088:25  */
    assign n1125_o = skipfirstr1byte ? error_code : n1120_o;
    /* sd_spi.vhd:1088:25  */
    assign n1127_o = skipfirstr1byte ? 1'b0 : skipfirstr1byte;
    /* sd_spi.vhd:1086:17  */
    assign n1129_o = state == 6'b101000;
    assign n1130_o = {
        n1129_o,
        n1103_o,
        n1101_o,
        n1097_o,
        n1073_o,
        n1071_o,
        n1069_o,
        n936_o,
        n859_o,
        n852_o,
        n837_o,
        n822_o,
        n789_o,
        n726_o,
        n724_o,
        n722_o,
        n684_o,
        n682_o,
        n677_o,
        n666_o,
        n654_o,
        n642_o,
        n635_o,
        n633_o,
        n624_o,
        n622_o,
        n613_o,
        n589_o,
        n587_o,
        n571_o,
        n547_o,
        n501_o,
        n484_o,
        n472_o,
        n460_o,
        n359_o,
        n357_o,
        n338_o,
        n336_o,
        n334_o,
        n332_o,
        n327_o,
        n309_o,
        n307_o,
        n296_o,
        n289_o,
        n287_o,
        n280_o,
        n273_o,
        n271_o,
        n269_o,
        n254_o,
        n229_o,
        n227_o,
        n219_o,
        n215_o
    };
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1162_o = n1122_o;
            56'b01000000000000000000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00100000000000000000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00010000000000000000000000000000000000000000000000000000: n1162_o = n1083_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1162_o = 6'b100101;
            56'b00000100000000000000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000010000000000000000000000000000000000000000000000000: n1162_o = n1050_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1162_o = n925_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1162_o = n857_o;
            56'b00000000010000000000000000000000000000000000000000000000: n1162_o = n840_o;
            56'b00000000001000000000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000000000100000000000000000000000000000000000000000000: n1162_o = n814_o;
            56'b00000000000010000000000000000000000000000000000000000000: n1162_o = n774_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000000000000100000000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000000000000010000000000000000000000000000000000000000: n1162_o = n713_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1162_o = 6'b110000;
            56'b00000000000000000100000000000000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000010000000000000000000000000000000000000: n1162_o = n671_o;
            56'b00000000000000000001000000000000000000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000100000000000000000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000010000000000000000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000001000000000000000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000100000000000000000000000000000000: n1162_o = n631_o;
            56'b00000000000000000000000010000000000000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000001000000000000000000000000000000: n1162_o = n620_o;
            56'b00000000000000000000000000100000000000000000000000000000: n1162_o = n603_o;
            56'b00000000000000000000000000010000000000000000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000001000000000000000000000000000: n1162_o = n580_o;
            56'b00000000000000000000000000000100000000000000000000000000: n1162_o = n564_o;
            56'b00000000000000000000000000000010000000000000000000000000: n1162_o = n535_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1162_o = n489_o;
            56'b00000000000000000000000000000000100000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000010000000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000001000000000000000000000: n1162_o = n447_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000010000000000000000000: n1162_o = n351_o;
            56'b00000000000000000000000000000000000001000000000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000000000100000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000010000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000001000000000000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000000100000000000000: n1162_o = n313_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000000000000001000000000000: n1162_o = n305_o;
            56'b00000000000000000000000000000000000000000000100000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000000000000000010000000000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000000000000000001000000000: n1162_o = n285_o;
            56'b00000000000000000000000000000000000000000000000100000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000000000000010000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000000000000001000000: n1162_o = 6'b100001;
            56'b00000000000000000000000000000000000000000000000000100000: n1162_o = n258_o;
            56'b00000000000000000000000000000000000000000000000000010000: n1162_o = n234_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1162_o = 6'b100011;
            56'b00000000000000000000000000000000000000000000000000000100: n1162_o = n225_o;
            56'b00000000000000000000000000000000000000000000000000000010: n1162_o = n217_o;
            56'b00000000000000000000000000000000000000000000000000000001: n1162_o = 6'b000001;
            default: n1162_o = 6'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b01000000000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00100000000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00010000000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00001000000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000100000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000010000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000001000000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000100000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000010000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000001000000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000100000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000010000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000001000000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000100000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000010000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000001000000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000100000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000010000000000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000001000000000000000000000000000000000000: n1176_o = 6'b101101;
            56'b00000000000000000000100000000000000000000000000000000000: n1176_o = 6'b101101;
            56'b00000000000000000000010000000000000000000000000000000000: n1176_o = n640_o;
            56'b00000000000000000000001000000000000000000000000000000000: n1176_o = 6'b101010;
            56'b00000000000000000000000100000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000010000000000000000000000000000000: n1176_o = 6'b100000;
            56'b00000000000000000000000001000000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000100000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000010000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000001000000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000100000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000010000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000001000000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000100000000000000000000000: n1176_o = 6'b011000;
            56'b00000000000000000000000000000000010000000000000000000000: n1176_o = 6'b011000;
            56'b00000000000000000000000000000000001000000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000100000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000010000000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000001000000000000000000: n1176_o = 6'b010011;
            56'b00000000000000000000000000000000000000100000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000010000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000001000000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000100000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000010000000000000: n1176_o = 6'b001110;
            56'b00000000000000000000000000000000000000000001000000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000100000000000: n1176_o = 6'b001100;
            56'b00000000000000000000000000000000000000000000010000000000: n1176_o = 6'b001011;
            56'b00000000000000000000000000000000000000000000001000000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000100000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000010000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000001000000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000100000: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000010000: n1176_o = n237_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1176_o = 6'b000100;
            56'b00000000000000000000000000000000000000000000000000000100: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000000010: n1176_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000000001: n1176_o = 6'b000000;
            default: n1176_o = 6'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b01000000000000000000000000000000000000000000000000000000: n1195_o = 6'b101000;
            56'b00100000000000000000000000000000000000000000000000000000: n1195_o = 6'b100111;
            56'b00010000000000000000000000000000000000000000000000000000: n1195_o = n1086_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000100000000000000000000000000000000000000000000000000: n1195_o = 6'b100100;
            56'b00000010000000000000000000000000000000000000000000000000: n1195_o = n1052_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000100000000000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000010000000000000000000000000000000000000000000000: n1195_o = n843_o;
            56'b00000000001000000000000000000000000000000000000000000000: n1195_o = n832_o;
            56'b00000000000100000000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000010000000000000000000000000000000000000000000: n1195_o = n776_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1195_o = 6'b110011;
            56'b00000000000000100000000000000000000000000000000000000000: n1195_o = 6'b110010;
            56'b00000000000000010000000000000000000000000000000000000000: n1195_o = n715_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000100000000000000000000000000000000000000: n1195_o = 6'b101111;
            56'b00000000000000000010000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000001000000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000100000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000010000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000001000000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000100000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000010000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000001000000000000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000100000000000000000000000000000: n1195_o = n605_o;
            56'b00000000000000000000000000010000000000000000000000000000: n1195_o = 6'b011101;
            56'b00000000000000000000000000001000000000000000000000000000: n1195_o = n582_o;
            56'b00000000000000000000000000000100000000000000000000000000: n1195_o = n566_o;
            56'b00000000000000000000000000000010000000000000000000000000: n1195_o = n537_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1195_o = n492_o;
            56'b00000000000000000000000000000000100000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000010000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000001000000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000100000000000000000000: n1195_o = 6'b010101;
            56'b00000000000000000000000000000000000010000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000001000000000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000100000000000000000: n1195_o = 6'b010010;
            56'b00000000000000000000000000000000000000010000000000000000: n1195_o = 6'b010001;
            56'b00000000000000000000000000000000000000001000000000000000: n1195_o = 6'b010000;
            56'b00000000000000000000000000000000000000000100000000000000: n1195_o = n316_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000001000000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000100000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000010000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000001000000000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000100000000: n1195_o = 6'b001001;
            56'b00000000000000000000000000000000000000000000000010000000: n1195_o = 6'b001000;
            56'b00000000000000000000000000000000000000000000000001000000: n1195_o = 6'b000111;
            56'b00000000000000000000000000000000000000000000000000100000: n1195_o = n261_o;
            56'b00000000000000000000000000000000000000000000000000010000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000001000: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000000100: n1195_o = 6'b000000;
            56'b00000000000000000000000000000000000000000000000000000010: n1195_o = 6'b000010;
            56'b00000000000000000000000000000000000000000000000000000001: n1195_o = 6'b000000;
            default: n1195_o = 6'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00100000000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00001000000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000001000000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000001000000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000100000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000100000000000000000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000010000000000000000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000001000000000000000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000100000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000001000000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000001000000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000010000000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000001000000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000000000100000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000000000000001000000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000000000000000010000000000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000000000000000001000000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1211_o = n240_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1211_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000100: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1211_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001: n1211_o = 1'b0;
            default: n1211_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00100000000000000000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00010000000000000000000000000000000000000000000000000000: n1231_o = n1089_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00000010000000000000000000000000000000000000000000000000: n1231_o = n1054_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1231_o = n846_o;
            56'b00000000001000000000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00000000000100000000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1231_o = n778_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00000000000000100000000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00000000000000010000000000000000000000000000000000000000: n1231_o = n717_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1231_o = 1'b1;
            56'b00000000000000000010000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000100000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000010000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000001000000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000100000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000001000000000000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1231_o = n607_o;
            56'b00000000000000000000000000010000000000000000000000000000: n1231_o = 1'b1;
            56'b00000000000000000000000000001000000000000000000000000000: n1231_o = n585_o;
            56'b00000000000000000000000000000100000000000000000000000000: n1231_o = n568_o;
            56'b00000000000000000000000000000010000000000000000000000000: n1231_o = n539_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1231_o = n495_o;
            56'b00000000000000000000000000000000100000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000010000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000001000000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000010000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000100000000000000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000010000000000000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000001000000000000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000000100000000000000: n1231_o = n319_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000001000000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000010000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000001000000000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000010000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000001000000: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000100000: n1231_o = n264_o;
            56'b00000000000000000000000000000000000000000000000000010000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000001000: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000100: n1231_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1231_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000001: n1231_o = 1'b0;
            default: n1231_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00100000000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00001000000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1235_o = n1057_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1235_o = n928_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000001000000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000100000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000100000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000010000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000001000000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000100000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000001000000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000001000000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000010000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000001000000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000100000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000001000000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000010000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000001000000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000001000: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000100: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1235_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001: n1235_o = 1'b0;
            default: n1235_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b01000000000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00100000000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00010000000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00001000000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000100000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000010000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000001000000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000100000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000010000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000001000000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000100000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000010000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000001000000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000100000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000010000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000001000000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000100000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000010000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000001000000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000100000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000010000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000001000000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000100000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000010000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000001000000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000100000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000010000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000001000000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000100000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000010000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000001000000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000100000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000010000000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000001000000000000000000000: n1240_o = n448_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000010000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000001000000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000100000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000010000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000001000000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000100000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000010000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000001000000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000100000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000010000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000001000000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000100000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000010000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000001000000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000000100000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000000010000: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000000001000: n1240_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000100: n1240_o = scs;
            56'b00000000000000000000000000000000000000000000000000000010: n1240_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000001: n1240_o = scs;
            default: n1240_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00100000000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00001000000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1243_o = n1059_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000001000000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000100000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000100000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000010000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000001000000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000100000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000001000000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000001000000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000010000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000001000000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000100000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000001000000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000010000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000001000000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000001000: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000100: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1243_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001: n1243_o = 1'b0;
            default: n1243_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b01000000000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00100000000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00010000000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00001000000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000100000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000010000000000000000000000000000000000000000000000000: n1250_o = n1019_o;
            56'b00000001000000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000100000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000010000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000001000000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000100000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000010000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000001000000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000100000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000010000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000001000000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000100000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000010000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000001000000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000100000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000010000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000001000000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000100000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000010000000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000001000000000000000000000000000000: n1250_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000010000000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000001000000000000000000000000000: n1250_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1250_o = n569_o;
            56'b00000000000000000000000000000010000000000000000000000000: n1250_o = n540_o;
            56'b00000000000000000000000000000001000000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000100000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000010000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000001000000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000100000000000000000000: n1250_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000001000000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000100000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000010000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000001000000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000100000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000010000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000001000000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000100000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000010000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000001000000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000100000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000010000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000001000000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000000100000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000000010000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000000001000:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000000000100:
            n1250_o = transfer_data_out;
            56'b00000000000000000000000000000000000000000000000000000010: n1250_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001:
            n1250_o = transfer_data_out;
            default: n1250_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1253_o = n1123_o;
            56'b01000000000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00100000000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00010000000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00001000000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000100000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000010000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000001000000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000100000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000010000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000001000000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000100000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000010000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000001000000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000100000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000010000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000001000000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000100000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000010000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000001000000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000100000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000010000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000001000000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000100000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000010000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000001000000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000100000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000010000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000001000000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000100000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000010000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000001000000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000100000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000010000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000001000000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000100000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000010000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000001000000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000100000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000010000000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000001000000000000000: n1253_o = n330_o;
            56'b00000000000000000000000000000000000000000100000000000000: n1253_o = n321_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000001000000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000100000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000010000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000001000000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000100000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000010000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000001000000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000000100000: n1253_o = n267_o;
            56'b00000000000000000000000000000000000000000000000000010000: n1253_o = n242_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000000000100: n1253_o = card_type;
            56'b00000000000000000000000000000000000000000000000000000010: n1253_o = 2'b00;
            56'b00000000000000000000000000000000000000000000000000000001: n1253_o = card_type;
            default: n1253_o = 2'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1256_o = n1124_o;
            56'b01000000000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00100000000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00010000000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00001000000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000100000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000010000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000001000000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000100000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000010000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000001000000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000100000000000000000000000000000000000000000000: n1256_o = n800_o;
            56'b00000000000010000000000000000000000000000000000000000000: n1256_o = n779_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000100000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000010000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000001000000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000100000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000010000000000000000000000000000000000000: n1256_o = n673_o;
            56'b00000000000000000001000000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000100000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000010000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000001000000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000100000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000010000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000001000000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000100000000000000000000000000000: n1256_o = n609_o;
            56'b00000000000000000000000000010000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000001000000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000100000000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000010000000000000000000000000: n1256_o = n541_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1256_o = n497_o;
            56'b00000000000000000000000000000000100000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000010000000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000001000000000000000000000: n1256_o = n449_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000010000000000000000000: n1256_o = n353_o;
            56'b00000000000000000000000000000000000001000000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000100000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000010000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000001000000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000100000000000000: n1256_o = n323_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000001000000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000100000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000010000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000001000000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000100000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000010000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000001000000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000000100000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000000010000: n1256_o = n244_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000000000100: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000000000010: n1256_o = error;
            56'b00000000000000000000000000000000000000000000000000000001: n1256_o = 1'b1;
            default: n1256_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1259_o = n1125_o;
            56'b01000000000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00100000000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00010000000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00001000000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000100000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000010000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000001000000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000100000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000010000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000001000000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000100000000000000000000000000000000000000000000: n1259_o = n802_o;
            56'b00000000000010000000000000000000000000000000000000000000: n1259_o = n780_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000100000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000010000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000001000000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000100000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000010000000000000000000000000000000000000: n1259_o = n675_o;
            56'b00000000000000000001000000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000100000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000010000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000001000000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000100000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000010000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000001000000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000100000000000000000000000000000: n1259_o = n611_o;
            56'b00000000000000000000000000010000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000001000000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000100000000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000010000000000000000000000000: n1259_o = n542_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1259_o = n499_o;
            56'b00000000000000000000000000000000100000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000010000000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000001000000000000000000000: n1259_o = n450_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000010000000000000000000: n1259_o = n355_o;
            56'b00000000000000000000000000000000000001000000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000100000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000010000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000001000000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000100000000000000: n1259_o = n325_o;
            56'b00000000000000000000000000000000000000000010000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000001000000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000100000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000010000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000001000000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000100000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000010000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000001000000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000000100000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000000010000: n1259_o = n246_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000000000100: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000000000010: n1259_o = error_code;
            56'b00000000000000000000000000000000000000000000000000000001: n1259_o = 3'b111;
            default: n1259_o = 3'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b01000000000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00100000000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00010000000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00001000000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000100000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000010000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000001000000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000100000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000010000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000001000000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000100000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000010000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000001000000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000100000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000010000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000001000000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000100000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000010000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000001000000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000100000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000010000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000001000000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000100000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000010000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000001000000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000100000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000010000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000001000000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000100000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000010000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000001000000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000100000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000010000000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000001000000000000000000000: n1262_o = n452_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000010000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000001000000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000100000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000010000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000001000000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000100000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000010000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000001000000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000100000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000010000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000001000000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000100000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000010000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000001000000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000100000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000010000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000001000: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000100: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000010: n1262_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000001: n1262_o = 1'b1;
            default: n1262_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b01000000000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00100000000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00010000000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00001000000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000100000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000010000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000001000000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000100000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000010000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000001000000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000100000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000010000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000001000000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000100000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000010000000000000000000000000000000000000000: n1265_o = n718_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000100000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000010000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000001000000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000100000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000010000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000001000000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000100000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000010000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000001000000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000100000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000010000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000001000000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000100000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000010000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000001000000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000100000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000010000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000001000000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000100000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000010000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000001000000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000100000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000010000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000001000000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000100000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000010000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000001000000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000100000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000010000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000001000000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000100000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000010000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000001000000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000100000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000010000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000001000: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000000100: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000000010: n1265_o = sdin_taken;
            56'b00000000000000000000000000000000000000000000000000000001: n1265_o = sdin_taken;
            default: n1265_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b01000000000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00100000000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00010000000000000000000000000000000000000000000000000000: n1274_o = n1091_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000100000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000010000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000001000000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000100000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000010000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000001000000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000100000000000000000000000000000000000000000000: n1274_o = n818_o;
            56'b00000000000010000000000000000000000000000000000000000000: n1274_o = n782_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000100000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000010000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000001000000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000100000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000010000000000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000001000000000000000000000000000000000000: n1274_o = n664_o;
            56'b00000000000000000000100000000000000000000000000000000000: n1274_o = n652_o;
            56'b00000000000000000000010000000000000000000000000000000000: n1274_o = n637_o;
            56'b00000000000000000000001000000000000000000000000000000000:
            n1274_o = 40'b0111011100000000000000000000000000000000;
            56'b00000000000000000000000100000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000010000000000000000000000000000000:
            n1274_o = 40'b0100110000000000000000000000000000000000;
            56'b00000000000000000000000001000000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000100000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000010000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000001000000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000100000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000010000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000001000000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000100000000000000000000000: n1274_o = n482_o;
            56'b00000000000000000000000000000000010000000000000000000000: n1274_o = n470_o;
            56'b00000000000000000000000000000000001000000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000100000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000010000000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000001000000000000000000:
            n1274_o = 40'b0111101100000000000000000000000000000001;
            56'b00000000000000000000000000000000000000100000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000010000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000001000000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000100000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000010000000000000:
            n1274_o = 40'b0111101000000000000000000000000000000000;
            56'b00000000000000000000000000000000000000000001000000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000100000000000: n1274_o = n294_o;
            56'b00000000000000000000000000000000000000000000010000000000:
            n1274_o = 40'b0111011100000000000000000000000000000000;
            56'b00000000000000000000000000000000000000000000001000000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000100000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000010000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000001000000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000000100000: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000000010000: n1274_o = n249_o;
            56'b00000000000000000000000000000000000000000000000000001000:
            n1274_o = 40'b0100000000000000000000000000000000000000;
            56'b00000000000000000000000000000000000000000000000000000100: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000000000010: n1274_o = 40'bX;
            56'b00000000000000000000000000000000000000000000000000000001: n1274_o = 40'bX;
            default: n1274_o = 40'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00100000000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1290_o = n1094_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000001000000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1290_o = n820_o;
            56'b00000000000010000000000000000000000000000000000000000000: n1290_o = n784_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000100000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000100000000000000000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000010000000000000000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000001000000000000000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000100000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000001000000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000001000000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000010000000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000001000000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000000000100000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000000000000001000000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000000000000000010000000000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000000000000000001000000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1290_o = n252_o;
            56'b00000000000000000000000000000000000000000000000000001000: n1290_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000100: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1290_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001: n1290_o = 1'b0;
            default: n1290_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b01000000000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00100000000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00010000000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00001000000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000100000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000010000000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000001000000000000000000000000000000000000000000000000: n1293_o = n929_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000010000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000001000000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000100000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000010000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000001000000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000100000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000010000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000001000000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000100000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000010000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000001000000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000100000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000010000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000001000000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000100000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000010000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000001000000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000100000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000010000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000001000000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000100000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000010000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000001000000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000100000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000010000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000001000000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000100000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000010000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000001000000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000100000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000010000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000001000000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000100000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000010000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000001000000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000100000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000010000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000001000000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000100000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000010000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000001000000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000100000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000010000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000001000: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000000100: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000000010: n1293_o = data_in;
            56'b00000000000000000000000000000000000000000000000000000001: n1293_o = data_in;
            default: n1293_o = 8'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b01000000000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00100000000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00010000000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00001000000000000000000000000000000000000000000000000000: n1296_o = 7'b0000000;
            56'b00000100000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000010000000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000001000000000000000000000000000000000000000000000000: n1296_o = n930_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000010000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000001000000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000100000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000010000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000001000000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000100000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000010000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000001000000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000100000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000010000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000001000000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000100000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000010000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000001000000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000100000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000010000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000001000000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000100000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000010000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000001000000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000100000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000010000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000001000000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000100000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000010000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000001000000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000100000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000010000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000001000000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000100000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000010000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000001000000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000100000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000010000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000001000000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000100000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000010000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000001000000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000100000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000010000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000001000000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000100000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000010000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000001000: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000000100: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000000010: n1296_o = crc7;
            56'b00000000000000000000000000000000000000000000000000000001: n1296_o = crc7;
            default: n1296_o = 7'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b01000000000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00100000000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00010000000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00001000000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000100000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000010000000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000001000000000000000000000000000000000000000000000000: n1299_o = n931_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000010000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000001000000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000100000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000010000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000001000000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000100000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000010000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000001000000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000100000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000010000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000001000000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000100000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000010000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000001000000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000100000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000010000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000001000000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000100000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000010000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000001000000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000100000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000010000000000000000000000000:
            n1299_o = 16'b0000000000000000;
            56'b00000000000000000000000000000001000000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000100000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000010000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000001000000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000100000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000010000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000001000000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000100000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000010000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000001000000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000100000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000010000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000001000000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000100000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000010000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000001000000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000100000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000010000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000001000000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000100000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000010000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000001000: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000000100: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000000010: n1299_o = in_crc16;
            56'b00000000000000000000000000000000000000000000000000000001: n1299_o = in_crc16;
            default: n1299_o = 16'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b01000000000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00100000000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00010000000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00001000000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000100000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000010000000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000001000000000000000000000000000000000000000000000000: n1302_o = n932_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000010000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000001000000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000100000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000010000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000001000000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000100000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000010000000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000001000000000000000000000000000000000000000:
            n1302_o = 16'b0000000000000000;
            56'b00000000000000000100000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000010000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000001000000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000100000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000010000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000001000000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000100000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000010000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000001000000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000100000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000010000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000001000000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000100000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000010000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000001000000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000100000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000010000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000001000000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000100000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000010000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000001000000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000100000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000010000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000001000000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000100000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000010000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000001000000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000100000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000010000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000001000000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000100000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000010000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000001000000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000100000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000010000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000001000: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000000100: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000000010: n1302_o = out_crc16;
            56'b00000000000000000000000000000000000000000000000000000001: n1302_o = out_crc16;
            default: n1302_o = 16'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b01000000000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00100000000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00010000000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00001000000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000100000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000010000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000001000000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000100000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000010000000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000001000000000000000000000000000000000000000000000: n1304_o = n833_o;
            56'b00000000000100000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000010000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000001000000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000100000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000010000000000000000000000000000000000000000: n1304_o = n719_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000100000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000010000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000001000000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000100000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000010000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000001000000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000100000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000010000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000001000000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000100000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000010000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000001000000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000100000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000010000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000001000000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000100000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000010000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000001000000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000100000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000010000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000001000000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000100000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000010000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000001000000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000100000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000010000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000001000000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000100000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000010000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000001000000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000100000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000010000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000001000000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000100000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000010000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000001000: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000000100: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000000010: n1304_o = crclow;
            56'b00000000000000000000000000000000000000000000000000000001: n1304_o = crclow;
            default: n1304_o = 8'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b01000000000000000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00100000000000000000000000000000000000000000000000000000: n1309_o = n1099_o;
            56'b00010000000000000000000000000000000000000000000000000000: n1309_o = n1095_o;
            56'b00001000000000000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000100000000000000000000000000000000000000000000000000: n1309_o = 8'b11111111;
            56'b00000010000000000000000000000000000000000000000000000000: n1309_o = n1061_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000100000000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000010000000000000000000000000000000000000000000000: n1309_o = n848_o;
            56'b00000000001000000000000000000000000000000000000000000000: n1309_o = n835_o;
            56'b00000000000100000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000010000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000001000000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000100000000000000000000000000000000000000000: n1309_o = crclow;
            56'b00000000000000010000000000000000000000000000000000000000: n1309_o = n720_o;
            56'b00000000000000001000000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000100000000000000000000000000000000000000: n1309_o = n680_o;
            56'b00000000000000000010000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000001000000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000100000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000010000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000001000000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000100000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000010000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000001000000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000100000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000010000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000001000000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000100000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000010000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000001000000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000100000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000010000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000001000000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000100000000000000000000: n1309_o = 8'b11111111;
            56'b00000000000000000000000000000000000010000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000001000000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000100000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000010000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000001000000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000100000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000010000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000001000000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000100000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000010000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000001000000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000100000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000010000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000001000000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000000100000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000000010000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000000001000: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000000000100: n1309_o = data_out;
            56'b00000000000000000000000000000000000000000000000000000010: n1309_o = 8'b11111111;
            56'b00000000000000000000000000000000000000000000000000000001: n1309_o = data_out;
            default: n1309_o = 8'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b01000000000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00100000000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00010000000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00001000000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000100000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000010000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000001000000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000100000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000010000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000001000000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000100000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000010000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000001000000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000100000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000010000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000001000000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000100000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000010000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000001000000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000100000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000010000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000001000000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000100000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000010000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000001000000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000100000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000010000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000001000000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000100000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000010000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000001000000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000100000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000010000000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000001000000000000000000000: n1313_o = n454_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000010000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000001000000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000100000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000010000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000001000000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000100000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000010000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000001000000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000100000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000010000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000001000000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000100000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000010000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000001000000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000000100000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000000010000: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000000001000:
            n1313_o = 32'b00000000000000000000000000000000;
            56'b00000000000000000000000000000000000000000000000000000100: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000000000010: n1313_o = 32'bX;
            56'b00000000000000000000000000000000000000000000000000000001: n1313_o = 32'bX;
            default: n1313_o = 32'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b01000000000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00100000000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00010000000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00001000000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000100000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000010000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000001000000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000100000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000010000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000001000000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000100000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000010000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000001000000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000100000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000010000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000001000000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000100000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000010000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000001000000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000100000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000010000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000001000000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000100000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000010000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000001000000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000100000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000010000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000001000000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000100000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000010000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000001000000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000100000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000010000000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000001000000000000000000000: n1316_o = n455_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000010000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000001000000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000100000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000010000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000001000000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000100000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000010000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000001000000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000100000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000010000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000001000000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000100000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000010000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000001000000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000100000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000010000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000001000: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000000100: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000000010: n1316_o = wr_erase_count;
            56'b00000000000000000000000000000000000000000000000000000001: n1316_o = wr_erase_count;
            default: n1316_o = 8'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00100000000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00001000000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000100000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000001000000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000001000000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000100000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000100000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000100000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000010000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000001000000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000100000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000001000000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000001000000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000010000000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000001000000000000000000000: n1320_o = n457_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000100000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000001000000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000010000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000001000000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000001000: n1320_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000100: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1320_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000001: n1320_o = 1'b0;
            default: n1320_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b01000000000000000000000000000000000000000000000000000000: n1328_o = 10'b0000001010;
            56'b00100000000000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00010000000000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00001000000000000000000000000000000000000000000000000000: n1328_o = 10'b0000000101;
            56'b00000100000000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000010000000000000000000000000000000000000000000000000: n1328_o = n1042_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000100000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000010000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000001000000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000100000000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000010000000000000000000000000000000000000000000: n1328_o = n785_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1328_o = 10'b0000001010;
            56'b00000000000000100000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000010000000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000001000000000000000000000000000000000000000: n1328_o = 10'b1000000000;
            56'b00000000000000000100000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000010000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000001000000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000100000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000010000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000001000000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000100000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000010000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000001000000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000100000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000010000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000001000000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000100000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000010000000000000000000000000: n1328_o = n543_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000100000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000010000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000001000000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000100000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000010000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000001000000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000100000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000010000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000001000000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000100000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000010000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000001000000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000100000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000010000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000001000000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000100000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000010000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000001000000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000000100000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000000010000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000000001000: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000000000100: n1328_o = byte_counter;
            56'b00000000000000000000000000000000000000000000000000000010: n1328_o = 10'b0000010100;
            56'b00000000000000000000000000000000000000000000000000000001: n1328_o = byte_counter;
            default: n1328_o = 10'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b01000000000000000000000000000000000000000000000000000000: n1336_o = 1'b1;
            56'b00100000000000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00010000000000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00001000000000000000000000000000000000000000000000000000: n1336_o = 1'b1;
            56'b00000100000000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000010000000000000000000000000000000000000000000000000: n1336_o = n1064_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000100000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000010000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000001000000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000100000000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000010000000000000000000000000000000000000000000: n1336_o = n787_o;
            56'b00000000000001000000000000000000000000000000000000000000: n1336_o = 1'b1;
            56'b00000000000000100000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000010000000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000001000000000000000000000000000000000000000: n1336_o = 1'b1;
            56'b00000000000000000100000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000010000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000001000000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000100000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000010000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000001000000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000100000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000010000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000001000000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000100000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000010000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000001000000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000100000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000010000000000000000000000000: n1336_o = n545_o;
            56'b00000000000000000000000000000001000000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000100000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000010000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000001000000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000100000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000001000000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000100000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000010000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000001000000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000100000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000010000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000001000000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000100000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000010000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000001000000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000100000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000010000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000001000000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000100000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000010000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000001000: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000100: n1336_o = 1'b0;
            56'b00000000000000000000000000000000000000000000000000000010: n1336_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000001: n1336_o = 1'b0;
            default: n1336_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b01000000000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00100000000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00010000000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00001000000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000100000000000000000000000000000000000000000000000000: n1341_o = 8'b00000111;
            56'b00000010000000000000000000000000000000000000000000000000: n1341_o = n1065_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000100000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000010000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000001000000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000100000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000010000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000001000000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000100000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000010000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000001000000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000100000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000010000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000001000000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000100000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000010000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000001000000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000100000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000010000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000001000000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000100000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000010000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000001000000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000100000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000010000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000001000000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000100000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000010000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000001000000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000100000000000000000000: n1341_o = 8'b00000111;
            56'b00000000000000000000000000000000000010000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000001000000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000100000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000010000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000001000000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000100000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000010000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000001000000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000100000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000010000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000001000000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000100000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000010000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000001000000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000100000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000010000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000001000: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000000100: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000000010: n1341_o = bit_counter;
            56'b00000000000000000000000000000000000000000000000000000001: n1341_o = bit_counter;
            default: n1341_o = 8'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b01000000000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00100000000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00010000000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00001000000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000100000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000010000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000001000000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000100000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000010000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000001000000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000100000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000010000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000001000000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000100000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000010000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000001000000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000100000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000010000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000001000000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000100000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000010000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000001000000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000100000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000010000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000001000000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000100000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000010000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000001000000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000100000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000010000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000001000000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000100000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000010000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000001000000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000100000000000000000000: n1345_o = 1'b0;
            56'b00000000000000000000000000000000000010000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000001000000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000100000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000010000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000001000000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000100000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000010000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000001000000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000100000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000010000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000001000000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000100000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000010000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000001000000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000000100000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000000010000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000000001000: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000000000100: n1345_o = slow_clock;
            56'b00000000000000000000000000000000000000000000000000000010: n1345_o = 1'b1;
            56'b00000000000000000000000000000000000000000000000000000001: n1345_o = slow_clock;
            default: n1345_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b01000000000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00100000000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00010000000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00001000000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000100000000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000010000000000000000000000000000000000000000000000000: n1348_o = n1067_o;
            56'b00000001000000000000000000000000000000000000000000000000: n1348_o = n934_o;
            56'b00000000100000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000010000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000001000000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000100000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000010000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000001000000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000100000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000010000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000001000000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000100000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000010000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000001000000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000100000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000010000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000001000000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000100000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000010000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000001000000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000100000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000010000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000001000000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000100000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000010000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000001000000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000100000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000010000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000001000000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000100000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000010000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000001000000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000100000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000010000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000001000000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000100000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000010000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000001000000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000100000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000010000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000001000000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000100000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000010000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000001000000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000000100000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000000010000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000000001000: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000000000100: n1348_o = clock_divider;
            56'b00000000000000000000000000000000000000000000000000000010: n1348_o = 7'b1000000;
            56'b00000000000000000000000000000000000000000000000000000001: n1348_o = clock_divider;
            default: n1348_o = 7'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b01000000000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00100000000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00010000000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00001000000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000100000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000010000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000001000000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000100000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000010000000000000000000000000000000000000000000000: n1350_o = n850_o;
            56'b00000000001000000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000100000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000010000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000001000000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000100000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000010000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000001000000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000100000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000010000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000001000000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000100000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000010000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000001000000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000100000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000010000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000001000000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000100000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000010000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000001000000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000100000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000010000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000001000000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000100000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000010000000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000001000000000000000000000: n1350_o = n458_o;
            56'b00000000000000000000000000000000000100000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000010000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000001000000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000100000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000010000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000001000000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000100000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000010000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000001000000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000100000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000010000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000001000000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000100000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000010000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000001000000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000100000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000010000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000001000: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000000100: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000000010: n1350_o = multiple;
            56'b00000000000000000000000000000000000000000000000000000001: n1350_o = multiple;
            default: n1350_o = 1'bX;
        endcase
    /* sd_spi.vhd:423:17  */
    always @*
        case (n1130_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1353_o = n1127_o;
            56'b01000000000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00100000000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00010000000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00001000000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000100000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000010000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000001000000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000100000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000010000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000001000000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000100000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000010000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000001000000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000100000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000010000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000001000000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000100000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000010000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000001000000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000100000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000010000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000001000000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000100000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000010000000000000000000000000000000: n1353_o = 1'b1;
            56'b00000000000000000000000001000000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000100000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000010000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000001000000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000100000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000010000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000001000000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000100000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000010000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000001000000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000100000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000010000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000001000000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000100000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000010000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000001000000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000100000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000010000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000001000000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000100000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000010000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000001000000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000100000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000010000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000001000000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000100000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000010000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000001000: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000000100: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000000010: n1353_o = skipfirstr1byte;
            56'b00000000000000000000000000000000000000000000000000000001: n1353_o = skipfirstr1byte;
            default: n1353_o = 1'bX;
        endcase
    /* sd_spi.vhd:1111:31  */
    assign n1357_o = state == 6'b000000;
    /* sd_spi.vhd:1112:31  */
    assign n1360_o = state == 6'b000001;
    /* sd_spi.vhd:1113:31  */
    assign n1363_o = state == 6'b000010;
    /* sd_spi.vhd:1114:31  */
    assign n1366_o = state == 6'b000011;
    /* sd_spi.vhd:1115:31  */
    assign n1369_o = state == 6'b000100;
    /* sd_spi.vhd:1116:31  */
    assign n1372_o = state == 6'b000101;
    /* sd_spi.vhd:1117:31  */
    assign n1375_o = state == 6'b000110;
    /* sd_spi.vhd:1118:31  */
    assign n1378_o = state == 6'b000111;
    /* sd_spi.vhd:1119:31  */
    assign n1381_o = state == 6'b001000;
    /* sd_spi.vhd:1120:31  */
    assign n1384_o = state == 6'b001001;
    /* sd_spi.vhd:1121:31  */
    assign n1387_o = state == 6'b001010;
    /* sd_spi.vhd:1122:31  */
    assign n1390_o = state == 6'b001011;
    /* sd_spi.vhd:1123:31  */
    assign n1393_o = state == 6'b001100;
    /* sd_spi.vhd:1124:31  */
    assign n1396_o = state == 6'b001101;
    /* sd_spi.vhd:1125:31  */
    assign n1399_o = state == 6'b001110;
    /* sd_spi.vhd:1126:31  */
    assign n1402_o = state == 6'b001111;
    /* sd_spi.vhd:1127:31  */
    assign n1405_o = state == 6'b010000;
    /* sd_spi.vhd:1128:31  */
    assign n1408_o = state == 6'b010001;
    /* sd_spi.vhd:1129:31  */
    assign n1411_o = state == 6'b010010;
    /* sd_spi.vhd:1130:31  */
    assign n1414_o = state == 6'b010011;
    /* sd_spi.vhd:1131:31  */
    assign n1417_o = state == 6'b010100;
    /* sd_spi.vhd:1132:31  */
    assign n1420_o = state == 6'b010101;
    /* sd_spi.vhd:1133:31  */
    assign n1423_o = state == 6'b010110;
    /* sd_spi.vhd:1134:31  */
    assign n1426_o = state == 6'b010111;
    /* sd_spi.vhd:1135:31  */
    assign n1429_o = state == 6'b011000;
    /* sd_spi.vhd:1136:31  */
    assign n1432_o = state == 6'b011001;
    /* sd_spi.vhd:1137:31  */
    assign n1435_o = state == 6'b011010;
    /* sd_spi.vhd:1138:31  */
    assign n1438_o = state == 6'b011011;
    /* sd_spi.vhd:1139:31  */
    assign n1441_o = state == 6'b011100;
    /* sd_spi.vhd:1140:31  */
    assign n1444_o = state == 6'b011101;
    /* sd_spi.vhd:1141:31  */
    assign n1447_o = state == 6'b011110;
    /* sd_spi.vhd:1142:31  */
    assign n1450_o = state == 6'b011111;
    /* sd_spi.vhd:1143:31  */
    assign n1453_o = state == 6'b100000;
    /* sd_spi.vhd:1144:31  */
    assign n1456_o = state == 6'b100001;
    /* sd_spi.vhd:1145:31  */
    assign n1459_o = state == 6'b100010;
    /* sd_spi.vhd:1146:31  */
    assign n1462_o = state == 6'b100011;
    /* sd_spi.vhd:1147:31  */
    assign n1465_o = state == 6'b100100;
    /* sd_spi.vhd:1148:31  */
    assign n1468_o = state == 6'b100101;
    /* sd_spi.vhd:1149:31  */
    assign n1471_o = state == 6'b100110;
    /* sd_spi.vhd:1150:31  */
    assign n1474_o = state == 6'b100111;
    /* sd_spi.vhd:1151:31  */
    assign n1477_o = state == 6'b101000;
    /* sd_spi.vhd:1152:31  */
    assign n1480_o = state == 6'b101001;
    /* sd_spi.vhd:1153:31  */
    assign n1483_o = state == 6'b101010;
    /* sd_spi.vhd:1154:31  */
    assign n1486_o = state == 6'b101011;
    /* sd_spi.vhd:1155:31  */
    assign n1489_o = state == 6'b101100;
    /* sd_spi.vhd:1156:31  */
    assign n1492_o = state == 6'b101101;
    /* sd_spi.vhd:1157:31  */
    assign n1495_o = state == 6'b110000;
    /* sd_spi.vhd:1158:31  */
    assign n1498_o = state == 6'b101110;
    /* sd_spi.vhd:1159:31  */
    assign n1501_o = state == 6'b101111;
    /* sd_spi.vhd:1160:31  */
    assign n1504_o = state == 6'b110001;
    /* sd_spi.vhd:1161:31  */
    assign n1507_o = state == 6'b110010;
    /* sd_spi.vhd:1162:31  */
    assign n1510_o = state == 6'b110011;
    /* sd_spi.vhd:1163:31  */
    assign n1513_o = state == 6'b110100;
    /* sd_spi.vhd:1164:31  */
    assign n1516_o = state == 6'b110101;
    /* sd_spi.vhd:1165:31  */
    assign n1519_o = state == 6'b110110;
    /* sd_spi.vhd:1166:31  */
    assign n1522_o = state == 6'b110111;
    assign n1523_o = {
        n1522_o,
        n1519_o,
        n1516_o,
        n1513_o,
        n1510_o,
        n1507_o,
        n1504_o,
        n1501_o,
        n1498_o,
        n1495_o,
        n1492_o,
        n1489_o,
        n1486_o,
        n1483_o,
        n1480_o,
        n1477_o,
        n1474_o,
        n1471_o,
        n1468_o,
        n1465_o,
        n1462_o,
        n1459_o,
        n1456_o,
        n1453_o,
        n1450_o,
        n1447_o,
        n1444_o,
        n1441_o,
        n1438_o,
        n1435_o,
        n1432_o,
        n1429_o,
        n1426_o,
        n1423_o,
        n1420_o,
        n1417_o,
        n1414_o,
        n1411_o,
        n1408_o,
        n1405_o,
        n1402_o,
        n1399_o,
        n1396_o,
        n1393_o,
        n1390_o,
        n1387_o,
        n1384_o,
        n1381_o,
        n1378_o,
        n1375_o,
        n1372_o,
        n1369_o,
        n1366_o,
        n1363_o,
        n1360_o,
        n1357_o
    };
    /* sd_spi.vhd:1110:17  */
    always @*
        case (n1523_o)
            56'b10000000000000000000000000000000000000000000000000000000: n1525_o = 8'b01001110;
            56'b01000000000000000000000000000000000000000000000000000000: n1525_o = 8'b01001101;
            56'b00100000000000000000000000000000000000000000000000000000: n1525_o = 8'b01001100;
            56'b00010000000000000000000000000000000000000000000000000000: n1525_o = 8'b01001011;
            56'b00001000000000000000000000000000000000000000000000000000: n1525_o = 8'b01001010;
            56'b00000100000000000000000000000000000000000000000000000000: n1525_o = 8'b01001001;
            56'b00000010000000000000000000000000000000000000000000000000: n1525_o = 8'b01001000;
            56'b00000001000000000000000000000000000000000000000000000000: n1525_o = 8'b01000111;
            56'b00000000100000000000000000000000000000000000000000000000: n1525_o = 8'b01000110;
            56'b00000000010000000000000000000000000000000000000000000000: n1525_o = 8'b01000101;
            56'b00000000001000000000000000000000000000000000000000000000: n1525_o = 8'b01000100;
            56'b00000000000100000000000000000000000000000000000000000000: n1525_o = 8'b01000011;
            56'b00000000000010000000000000000000000000000000000000000000: n1525_o = 8'b01000010;
            56'b00000000000001000000000000000000000000000000000000000000: n1525_o = 8'b01000001;
            56'b00000000000000100000000000000000000000000000000000000000: n1525_o = 8'b01000000;
            56'b00000000000000010000000000000000000000000000000000000000: n1525_o = 8'b00110111;
            56'b00000000000000001000000000000000000000000000000000000000: n1525_o = 8'b00110110;
            56'b00000000000000000100000000000000000000000000000000000000: n1525_o = 8'b00110101;
            56'b00000000000000000010000000000000000000000000000000000000: n1525_o = 8'b00110100;
            56'b00000000000000000001000000000000000000000000000000000000: n1525_o = 8'b00110011;
            56'b00000000000000000000100000000000000000000000000000000000: n1525_o = 8'b00110010;
            56'b00000000000000000000010000000000000000000000000000000000: n1525_o = 8'b00110001;
            56'b00000000000000000000001000000000000000000000000000000000: n1525_o = 8'b00110000;
            56'b00000000000000000000000100000000000000000000000000000000: n1525_o = 8'b00101001;
            56'b00000000000000000000000010000000000000000000000000000000: n1525_o = 8'b00101000;
            56'b00000000000000000000000001000000000000000000000000000000: n1525_o = 8'b00100111;
            56'b00000000000000000000000000100000000000000000000000000000: n1525_o = 8'b00100110;
            56'b00000000000000000000000000010000000000000000000000000000: n1525_o = 8'b00100101;
            56'b00000000000000000000000000001000000000000000000000000000: n1525_o = 8'b00100100;
            56'b00000000000000000000000000000100000000000000000000000000: n1525_o = 8'b00100011;
            56'b00000000000000000000000000000010000000000000000000000000: n1525_o = 8'b00100010;
            56'b00000000000000000000000000000001000000000000000000000000: n1525_o = 8'b00100001;
            56'b00000000000000000000000000000000100000000000000000000000: n1525_o = 8'b00100000;
            56'b00000000000000000000000000000000010000000000000000000000: n1525_o = 8'b00100000;
            56'b00000000000000000000000000000000001000000000000000000000: n1525_o = 8'b00010001;
            56'b00000000000000000000000000000000000100000000000000000000: n1525_o = 8'b00010000;
            56'b00000000000000000000000000000000000010000000000000000000: n1525_o = 8'b00001010;
            56'b00000000000000000000000000000000000001000000000000000000: n1525_o = 8'b00001001;
            56'b00000000000000000000000000000000000000100000000000000000: n1525_o = 8'b00001000;
            56'b00000000000000000000000000000000000000010000000000000000: n1525_o = 8'b00001000;
            56'b00000000000000000000000000000000000000001000000000000000: n1525_o = 8'b00001000;
            56'b00000000000000000000000000000000000000000100000000000000: n1525_o = 8'b00001000;
            56'b00000000000000000000000000000000000000000010000000000000: n1525_o = 8'b00001000;
            56'b00000000000000000000000000000000000000000001000000000000: n1525_o = 8'b00000111;
            56'b00000000000000000000000000000000000000000000100000000000: n1525_o = 8'b00000110;
            56'b00000000000000000000000000000000000000000000010000000000: n1525_o = 8'b00000101;
            56'b00000000000000000000000000000000000000000000001000000000: n1525_o = 8'b00000100;
            56'b00000000000000000000000000000000000000000000000100000000: n1525_o = 8'b00000100;
            56'b00000000000000000000000000000000000000000000000010000000: n1525_o = 8'b00000100;
            56'b00000000000000000000000000000000000000000000000001000000: n1525_o = 8'b00000100;
            56'b00000000000000000000000000000000000000000000000000100000: n1525_o = 8'b00000100;
            56'b00000000000000000000000000000000000000000000000000010000: n1525_o = 8'b00000011;
            56'b00000000000000000000000000000000000000000000000000001000: n1525_o = 8'b00000010;
            56'b00000000000000000000000000000000000000000000000000000100: n1525_o = 8'b00000001;
            56'b00000000000000000000000000000000000000000000000000000010: n1525_o = 8'b00000000;
            56'b00000000000000000000000000000000000000000000000000000001: n1525_o = 8'b00000000;
            default: n1525_o = 8'bX;
        endcase
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1526_q <= n122_o;
    initial n1526_q = 6'b000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1527_q <= n124_o;
    initial n1527_q = 6'b000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1528_q <= n126_o;
    initial n1528_q = 6'b000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1529_q <= n128_o;
    initial n1529_q = 1'b1;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1530_q <= n130_o;
    initial n1530_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1531_q <= n132_o;
    initial n1531_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1532_q <= n134_o;
    initial n1532_q = 2'b00;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1533_q <= n136_o;
    initial n1533_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1534_q <= n138_o;
    initial n1534_q = 3'b000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1535_q <= n140_o;
    initial n1535_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1536_q <= n142_o;
    initial n1536_q = 40'b1111111111111111111111111111111111111111;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1537_q <= n144_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1538_q <= n146_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1539_q <= n148_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1540_q <= n150_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1541_q <= n152_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1542_q <= n154_o;
    initial n1542_q = 8'b00000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1543_q <= n156_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1544_q <= n158_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1545_q <= n160_o;
    initial n1545_q = 10'b0000000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1546_q <= n162_o;
    initial n1546_q = 8'b00000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1547_q <= n164_o;
    initial n1547_q = 1'b1;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1548_q <= n166_o;
    initial n1548_q = 7'b0000000;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1549_q <= n168_o;
    initial n1549_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1550_q <= n170_o;
    initial n1550_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1551_q <= n171_o;
    initial n1551_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1552_q <= n172_o;
    initial n1552_q = 1'b0;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1553_q <= n102_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1554_q <= n104_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1555_q <= n106_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1556_q <= n108_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1557_q <= n110_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1558_q <= n112_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1559_q <= n114_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1560_q <= n116_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1561_q <= n118_o;
    /* sd_spi.vhd:269:17  */
    always @(posedge clk) n1562_q <= n120_o;
endmodule

