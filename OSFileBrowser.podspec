#
#  Be sure to run `pod spec lint OSFileBrowser.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "OSFileBrowser"
  s.version      = "0.0.9"
  s.summary      = "一个很实用的文件浏览器."
  s.description  = "一个很实用的本地浏览器，平时开发时，你可以很简单的访问沙盒，查看信息"

  s.homepage     = "https://github.com/Ossey/FileBrowser"
  s.license      = "MIT"

  s.author             = { "Ossey" => "xiaoyuan1314@me.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/Ossey/FileBrowser.git", :tag => "#{s.version}" }

  s.source_files  = "FileBrowser", "OSFileBrowser/*.{h,m}"
  s.resource     = 'OSFileBrowser/OSFileBrowser.bundle'
  s.requires_arc = true
  s.frameworks = 'UIKit'
  s.dependency 'MBProgressHUD', '~> 1.0.0'
  s.dependency 'NODataPlaceholderView', '~> 1.0.2'
  s.dependency 'OSFileManager', '~> 0.0.1'
end