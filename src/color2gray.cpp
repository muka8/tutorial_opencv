#include <ros/ros.h>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
	//コマンドライン引数の確認
	if(argc<3){
		ROS_ERROR("Usage is %s [input image] [output image]", argv[0]);
		return -1; //引数不足のときノード終了
	}
	//ROSの初期化
	ros::init(argc, argv, "color2gray");
	//画像ファイルの読み込み
	cv::Mat color_img = cv::imread(argv[1], 1);
	//画像ファイルの読み込みに失敗しらた終了
	if(color_img.empty()){
		ROS_ERROR("Failed to load %s", argv[1]);
		return -1;
	}
	//出力画像の変数を宣言
	cv::Mat gray_img(color_img.rows, color_img.cols, CV_8UC1);
	//カラー画像からグレースケール画像に変換
	for(int y=0; y<gray_img.rows; y++){
		for(int x=0; x<gray_img.cols; x++){
			cv::Vec3b val = color_img.at<cv::Vec3b>(y, x);
			gray_img.at<uchar>(y, x) = 0.114 * val[0] + 0.587 * val[1] + 0.299 * val[2];
		}
	}
	//変換した画像の表示
	cv::imshow("Grayscale", gray_img);
	cv::waitKey(0); //ウィンドウ上で何かキーが押されるまで待機
	//指定したディレクトリにグレースケール画像を保存
	cv::imwrite(argv[2], gray_img);
	return 0;
}

