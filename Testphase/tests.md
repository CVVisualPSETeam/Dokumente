#Tests
##Automatic Tests
...
##Manual Tests
###Accordion
__Source:__ /manual\_test/accordion

__Excutable:__ /build/debug/test\_manual\_acordion

__Accordion Test:__

 - a window with several buttons ("pfront", "pback", "insert elem at pos 5",
 "remove last element inserted at 5", "clear", "hideAll", "hide5", "showAll",
 "show5", "collapseAll", "collapse5", "expandAll", "expand5") and an empty area
 - "pfront" will insert a collapsable with text and title 0 at the beginning
 - "pback" will insert a collapsable with text and title end at the end
 - "clear" will delete all elements
- "hideAll" will hide all collapsables
- "showAll" will show all collapsables
- "collapseAll" will collapse all collapsables
- "expandAll" will expand all collapsables
- "insert elem at pos 5" will insert a collapsable (elem5) with text and
title 5 at position 5
- "remove last element inserted at 5" will remove the last elem5
- "hide5" will hide the last elem5
- "show5" will show the last elem5
- "collapse5" will collapse the last elem5
- "expand5" will expand the last elem5
- if there is no elem5 a window with following text will pop up:
	no last element inserted at 5. (maybe already deleted)
- if "insert elem at pos 5" is used 2 times and "remove last element inserted at 5"
 is calles there is NO elem5 (the second is deleted, the first one is not set as elem5)
- beginning /end / pos 5 refer to the empty area at the bottom
- all buttons behave as described
- the area displays scrollbars if needed
###AutoFilterWidget
__Source:__ /manual\_test/autofilterwidget

__Excutable:__ /build/debug/test\_manual\_autofilterwidget

__AutoFilterWidget Test:__

- a window will pop up
- it has 3 columns
- the first contains an accordion wit 3 elements ("button user select",
 "button individual filter", "afw")
- the 2nd column contains a black image ( 6 channels, all pixel
{2;1;2147483640;2147483640;2147483640;2147483640}
- the 3rd column contains a blue image with a black line
- the visible are (zoom+ area) of the left image will be applyed to the right image
- if "button user select" is toggled there are two checkboxes ("i1", "i2")
in the top of "afw"
- in afw the user can select filters to apply to both images (only checked ones are used)
- the filtered image will appear below the orginal one
- if the filter can not be applied to an image a red error message will appear in at the top of afw
- if "button individual filter" is not checked filter are applied only if there are no error messages
- filters are: "Sobel", "Gray filter", "Reorder channels"
- "Sobel" can not be applied to the left image
- "Sobel" represents the sobel filter
- "Gray filter" can apply a gray filter to both images
(the factors for each channel can be choosen by the user)
- "Reorder channels" can reorder the channels of the orginal image
(number and order of the output channels can be selected)
###Collapsable
__Source:__ /manual\_test/collapsable

__Excutable:__ /build/debug/test\_manual\_collapsable

__Collapsable Test:__

- a window with a button will open
- the button can be toggled
- if toggled the window will expand and display following text:

        some
        text "with
        newlines



        loooooooooooooooooooooooooong line
###Debug Printer
__Source:__ /manual\_test/dbg_printer

__Excutable:__ /build/debug/test\_manual\_dbg\_printer
###DefaultFilterView
__Source:__ /manual\_test/defaultfilterviewtest

__Excutable:__ /build/debug/test\_manual\_defaultfilterview

__DefaultFilterView Test:__

Give images as program arguments.

A window should open with an accordion menu on the left and as many images as
you passed to the test on the right.
 
The accordion menu should consist of the following collapsables:

- ___Zoom sychronization:___
                When opened one plus as many checkboxes as there are images should be
                displayed. One for every image and one to indicate that no zoom
                synchronization is selected.
                If one image is selected, zooming or scrolling in this image is mapped to
                the other image so they all show the same section and have the same zoom
                level. Zooming or scrolling in a non-selected image only changes this image,
                as it would if no zoom synchronization was selected.
- ___Image Information x:___
                For each image there is a widget which displays information about the image.
                Zooming in and out of an image with both the spin box in the image information
                and (Shift) + Strg + Mouse Wheel should work (Shift: slower).
                Unchecking "Show image" should make it disappear, checking make it reappear.
                The information about the image in the collapsable should be correct.
                "Show full image" should work.
###DepthMatchView
__Source:__ /manual\_test/depthviewtest

__Excutable:__ /build/debug/test\_manual\_depthviewtest

__DepthMatchView Test:__

This test shows a depthmatchview, it should only end if you close the window manually.
The matches should be schow as points with a radius with is proportional to the match distance,
keypoints arent visible nad/or selecteable.

All classes like zoomableimage, zoomableoptpane, synczoomwidget, match Management,...
should work correctly.

___"Match Settings":___
        you can select matches with the selections and settings should only applied to the selected
        matches.

___"KeyPoint Settings":___
        see match settings

___"Image Information":___
        the zoomableoptpanel should show all informations of the cv::Mat correctly and the zoom
        should be syncron with the zoomabelImage

___"syncWidget":___
        you can choose that the zoom in one image should do the same in the other images, or none

Parameter argv: arguments executablepath, image path1, imagepath 2.
return 0.
###DualFilterView
__Source:__ /manual\_test/dual\_filter_filter

__Excutable:__ /build/debug/test\_manual\_dualfilterview

__DualFilterView Test:__

Give an image as the argument when running the test.

A window should open with an accordion menu on the left and three images on the
right, ordered as follows:
The first image should be the image given as argument and the third its
dilated counterpart.
The image in the middle should be the result of the selected filter being
applied to the two outer images. At the beginning no filter is selected, so
the middle image is the same as the left image.
 
The accordion menu should consist of the following collapsables:

- ___Select a filter:___
                A comboBox allows you to select the filter (Changed Pixels, Difference,
                Overlay). When a filter is selected you can choose is settings below
                the comboBox.
                The Changed Pixels filter marks changed pixels as black and unchanged
                pixels as white.
                The Difference filter shows either the difference for every channel
                (grayscale), or the difference between the two images' hue, saturation
                or value. The requestes filter type can be selected through a comboBox.
                 The Overlay filter adds the two images (overlays them) where the weight
                of the right images is shown and changable by a slider.
                To apply the selectedFilter press the 'apply' Button. When you change the
                filter or the filter settings after you have pressed apply, the new filter
                is automatically applied to the selected images.
- ___Zoom sychronization:___
                When opened four checkboxes should be displayed. One for every image and
                one to indicate that no zoom synchronization is selected.
                If one image is selected, zooming or scrolling in this image is mapped to
                the other image so they all show the same section and have the same zoom
                level. Zooming or scrolling in a non-selected image only changes this image,
                as it would if no zoom synchronization was selected.
- ___Image Information x:___
                For each image there is a widget which displays information about the image.
                Zooming in and out of an image with both the spin box in the image information
                and (Shift) + Strg + Mouse Wheel should work (Shift: slower).
                Unchecking "Show image" should make it disappear, checking make it reappear.
                The information about the image in the collapsable should be correct.
                "Show full image" should work.
###FilterCallTab
__Source:__ /manual\_test/filter\_call_tab

__Excutable:__ /build/debug/test\_manual\_filtercalltab

__FilterCallTab Test:__

1. Start the test.
Two windows should appear, one showing SingleFilterView,
the other whichever View is currently set as default
(check the CVVisual file).
[-> all Constructors work]
In each window, on the top there should be (left to right)
a label reading "View:", a ComboBox displaying the name of the current view,
a "Set as default" and a "Help" button.
Below should be the View selected in the ComboBox
(refer to the respective View's test;
the images are entirely black and of size 100x100).
[-> GUI is complete]

2. Close the SingleFilterView window.
In the other, open a collapsable of the accordion menu.

3. Switch to another view. It should appear correctly.
[-> Switching Views works].
Click "Set as default".

4. Click "Help". The help page of this view should open in a web browser.
[-> Help works]

5. Switch back to the original view.
The accordion collapsable should still be open.
[-> History works]

6. Close the window. There should be no segfaults or other problems.
[-> Closing works]

7. Run the test again to see if the window showing the default View
now shows the one you set as default before.
[-> "Set as default" works]
###Filters
__Source:__ /manual\_test/filters

__Excutable:__ /build/debug/test\_manual\_filters

__Filters Test:__

This test filters  all the provided images with erode(), dilate(), Sobel() and morphologyEx()
and visualizes these filters with the debug-framework.

Expected behaviour:
A Mainwindow should open that shows an overview-table containing the first image and it's dilated
  version.
Upon klicking step multiple times or '>>' once, all further images and filters should appear in
  the table.
All calls can be opened in any existing window or in a new one. It is possible to select all the
  different filter-visualisations for all of them.
Closing calltabs should work. Closing the last tab of a window results in the closing of the window
Clicking the Close-button results in the termination of the program with 0 as exit-status.
###finalShow Crash
__Source:__ /manual\_test/final\_show_crash

__Excutable:__ /build/debug/test\_manual\_final\_show\_crash
###FilterSelectorWidget
__Source:__ /manual\_test/fsw

__Excutable:__ /build/debug/test\_manual\_fsw

__FilterSelectionWidget Test:__

- a window will pop up
- it will contain a combo box (options "A", "B", initialli "A" is selected)
  a text ("A")
  and a button ("apply")
- if a option X from the combo box is selected the text will change to "X"
- if a option is selected the button will move beneath the combo box
###(Single)ImageCallTab
__Source:__ /manual\_test/image\_call_tab

__Excutable:__ /build/debug/test\_manual\_imagecalltab

__ImageCallTab Test:__

1. Start the test.
Two windows should appear, both showing ImageView (refer to its test;
the image is entirely black and of size 100x100).
[-> all Constructors work]
In each window, on the top above the View there should be (left to right)
a label reading "Single Image View" and a "Help" button.
[-> GUI is complete]

2. Click "Help".
The help page of Single Image View should open in a web browser.
[-> Help works]
###Image Conversion
__Source:__ /manual\_test/imageconvert

__Excutable:__ /build/debug/test\_manual\_imageconvert

__Image Conversion Test:__

- two windows will pop up ("rook_window", "test\_manual\_imageconvert")
- rook_window will contain an image of a red rook on a black background with a
yellow line underneath it
- test\_manual_imageconvert will contain two identical rows of images
- the images look like:
light gray square, red square, light green square, blue square,
gray square, dark green square, yellow-green square and the rook image.
- following text will be printed:

		will now create mats
		done all
		will now convert
		done 12345678
		done all
		will now test result
		1
		1
		1
		1
		1
		1
		1
		1
		done all
		will now print formats 0=Invalid, 3=Indexed8, 5=ARGB32, 13=RGB888
		3
		13
		13
		13
		5
		13
		13
		13
		create widget
		create vbox
		create hbox
		set widget layout to vbox
		add hbox to vbox
		will create labels........
		create labels
		 1234567 => all8 => all
		convert to pixmaps start
		done 12345678 => all
		convert to pixmaps end
		now everything with pixmaps
		convert to pixmaps start
		convert to pixmaps end

###Image Conversion Performance
__Source:__ /manual\_test/imageconvertperf

__Excutable:__ /build/debug/test\_manual\_imageconvertperf

__Image Conversion Performance Test:__

- "qt allows images with: 1000 M pixels" will be printed if qt allows the craetion of
  1 G pixel images
- "# threads?:" will be printed and the user has to enter the number of threads to use
- the following text will be printed where XXXX is the time needed to execute (in ms)

		##test:
		depth 30	pixel: 1 M pixels	success: 1	time: XXXX
		##test:
		depth 28	pixel: 1 M pixels	success: 1	time: XXXX
		##test:
		depth 30	pixel: 10 M pixels	success: 1	time: XXXX
		##test:
		depth 28	pixel: 10 M pixels	success: 1	time: XXXX
		continue with 100M pixel test? will need about 3,2 gig mem (y)
- if the user enters anything other than y the programm will exit
- if y was entered the following text will be printed where XXXX is the
 time needed to execute (in ms)

		##test:
		depth 30	pixel: 100 M pixels	success: 1	time: XXXX
		##test:
		depth 28	pixel: 100 M pixels	success: 1	time: XXXX
###(Single)ImageView
__Source:__ /manual\_test/imageview

__Excutable:__ /build/debug/test\_manual\_imageview

__(Single)ImageView Test:__

Give an image as the argument when running the test.
It should appear correctly on the right.
On the left should be an accordion menu consisting of only
one collapsable, "ImageInformation:".
Open it.
Zooming in and out of the image with both the spin box
and (Shift) + Strg + Mouse Wheel should work (Shift: slower).
The information about the image in the collapsable should be correct.
"Show full image" should work.
###LineMatchView
__Source:__ /manual\_test/linematchviewtest

__Excutable:__ /build/debug/test\_manual\_linematchviewtest

__LinematchView Test:__

This test shows a linematchview, it should only end if you close the window manually.
The matches should be shown as line between the keypoints in the images.

All classes like zoomableimage, zoomableoptpane, synczoomwidget, match Management,...
should work correctly.

___"Match Settings":___
        you can select matches with the selections and settings should only applied to the selected
        matches.

___"KeyPoint Settings":___
        see match settings

___"Image Information":___
        the zoomableoptpanel should show all informations of the cv::Mat correctly and the zoom
        should be syncron with the zoomabelImage

___"syncWidget":___
        you can choose that the zoom in one image should do the same in the other images, or none

Parameter argv: arguments executablepath, image path1, imagepath 2.
return 0.
###Matches
__Source:__ /manual\_test/match

__Excutable:__ /build/debug/test\_manual\_match

__Match Test:__

This test creates random matches of random quality on all the provided images and scales
them down for a copy of the same image.

Expected behaviour:
A Mainwindow should open that shows an overview-table containing matches from the first image to itself
Upon klicking step multiple times or '>>' once, all further images should appear in the table.
All calls can be opened in any existing window or in a new one. It is possible to select all the
  different match-visualisations for all of them.
Closing calltabs should work. Closing the last tab of a window results in the closing of the window
Clicking the Close-button results in the termination of the program with 0 as exit-status.
###MatchCallTab
__Source:__ /manual\_test/match\_call_tab

__Excutable:__ /build/debug/test\_manual\_matchcalltab

__MatchCallTab Test:__

1. Start the test. Two windows should appear, one showing RawView,
the other whichever View is currently set as default
(check the CVVisual file).
[-> all Constructors work]
In each window, on the top there should be (left to right)
a label reading "View:", a ComboBox displaying the name of the current view,
a "Set as default" and a "Help" button.
Below should be the View selected in the ComboBox
(refer to the respective View's test;
the images are entirely black and of size 1000x1000).
[-> GUI is complete]

2. Close the RawView window.
In the other, open a collapsable of the accordion menu.

3. Switch to another view. It should appear correctly.
[-> Switching Views works].
Click "Set as default".

4. Click "Help". The help page of this view should open in a web browser.
[-> Help works]

5. Switch back to the original view.
The accordion collapsable should still be open.
[-> History works]

6. Close the window. There should be no segfaults or other problems.
[-> Closing works]

7. Run the test again to see if the window showing the default View
now shows the one you set as default before.
[-> "Set as default" works]
###Multiple Calls
__Source:__ /manual\_test/multiple_calls

__Excutable:__ /build/debug/test\_manual\_multiple\_final\_calls
###MultiViewCallTab
__Source:__ /manual\_test/multiview\_call_tab

__Excutable:__ /build/debug/test\_manual\_multiviewcalltab

__MultiViewCallTab Test:__

1. Start the test.
Three windows should appear, one showing SingleFilterView,
the others whichever View is currently set as default
(check the CVVisual file on default_filter_views).
[-> all Constructors work]
In each window, on the top there should be (left to right)
a label reading "View:", a ComboBox displaying the name of the current view,
a "Set as default" and a "Help" button.
Below should be the View selected in the ComboBox
(refer to the respective View's test;
the images are entirely black and of size 100x100).
[-> GUI is complete]

2. Close the SingleFilterView window and one of the others.
In the last, open a collapsable of the accordion menu.

3. Switch to another view. It should appear correctly.
[-> Switching Views works].
Click "Set as default".

4. Click "Help". The help page of this view should open in a web browser.
[-> Help works]

5. Switch back to the original view.
The accordion collapsable should still be open.
[-> History works]

6. Close the window. There should be no segfaults or other problems.
[-> Closing works]

7. Run the test again to see if the windows showing the default View
now both show the one you set as default before.
[-> "Set as default" works]
###RegisterHelper
__Source:__ /manual\_test/registerhelper

__Excutable:__ /build/debug/test\_manual\_registerhelper

__RegisterHelper Test:__

- a window will pop up
- the window contains a button ("add") and two identical subwidgets below each other
- the subwidget contains a combobox (initially "A") and a text (initially "A")
- the cobobox starts with the options "A" and "B"
- every time the button "add" is pressed both comboboxes will get a new entry "X"
- if that enty is selected the text will be "X"
- X is a number. it starts at 2 and is incremented for each click
- if a option X in a combobox is selected the text

                ~current selection	X
                ~txt of func	X
is printed to std::out
(some other debug thext is printed too)
###SignalSlot
__Source:__ /manual\_test/signalslot

__Excutable:__ /build/debug/test\_manual\_signslot

__SignalSlot Test:__

- a window will pop up
- it will contain a button ("push me") and below that a text ("pressed: 0")
- if the button is pressed the nub´mber in the text will increment
###Single Image
__Source:__ /manual\_test/single_image

__Excutable:__ /build/debug/test\_manual\_single\_image

__SingleImage Test:__

This test shows all the provided images using the debug-framework.

Expected behaviour:
A Mainwindow should open that shows an overview-table containing the first imagei
Upon klicking step multiple times or '>>' once, all further images and filters should appear in
  the table.
All calls can be opened in any existing window or in a new one.
Closing calltabs should work. Closing the last tab of a window results in the closing of the window
Clicking the Close-button results in the termination of the program with 0 as exit-status.
###SingleFilterView
__Source:__ /manual\_test/singlefilterviewtest

__Excutable:__ /build/debug/test\_manual\_singlefilterview

__SingleFilterView Test:__

Give an image as the argument when running the test.

A window should open with an accordion menu on the left and four images on the
right, ordered as follows:
The top two images should be the image given as argument to the left and its
dilated counterpart to the right.
Below each of the two images the image should be shown with the selected filter
applied to it. At the beginning no filter is selected, so the lower images are
the same as the upper images.
 
The accordion menu should consist of the following collapsables:

- ___Select a filter:___
                If opened a checkbox for each original image should be shown, indicating
                whether the selected filter is to be applied to the respective image.
                A comboBox allows you to select the filter (gray filter, reorder channels
                and soebel). When a filter is selected you can choose is settings below
                the comboBox.
                To apply the selectedFilter press the 'apply' Button. When you change the
                filter or the filter settings after you have pressed apply, the new filter
                is automatically applied to the selected images.
- ___Zoom sychronization:___
                When opened five checkboxes should be displayed. One for every image and
                one to indicate that no zoom synchronization is selected.
                If one image is selected, zooming or scrolling in this image is mapped to
                the other image so they all show the same section and have the same zoom
                level. Zooming or scrolling in a non-selected image only changes this image,
                as it would if no zoom synchronization was selected.
- ___Info image x:___
                For each image there is a widget which displays information about the image.
                Zooming in and out of an image with both the spin box in the image information
                and (Shift) + Strg + Mouse Wheel should work (Shift: slower).
                Unchecking "Show image" should make it disappear, checking make it reappear.
                The information about the image in the collapsable should be correct.
                "Show full image" should work.
###Test All
__Source:__ /manual\_test/test_all

__Excutable:__ /build/debug/test\_manual\_all

__Test All:__

This test shows all the provided images and filters them using morphologyEx() using the
debug-framework.

Expected behaviour:
A Mainwindow should open that shows an overview-table containing the first imagei
Upon klicking step multiple times or '>>' once, all further images and filters should appear in
  the table.
All calls can be opened in any existing window or in a new one. For the filtered Images it is
  possible to select all the different filter-visualisations for all of them.
Closing calltabs should work. Closing the last tab of a window results in the closing of the window
Clicking the Close-button results in the termination of the program with 0 as exit-status.
###TranslationMatchView
__Source:__ /manual\_test/translationviewtest

__Excutable:__ /build/debug/test\_manual\_translationviewtest

__TranslationMatchView Test:__

This test shows a translationview, it should only end if you close the window manual.
The matches should be shown as translation lines in the images, a line should only be in one image.

All classes like zoomableimage, zoomableoptpane, synczoomwidget, match Management,...
should work correctly.

___"Match Settings":___
        you can select matches with the selections and settings should only applied to the selected
        matches.

___"KeyPoint Settings":___
        see match settings

___"Image Information":___
        the zoomableoptpanel should show all informations of the cv::Mat correctly and the zoom
        should be syncron with the zoomabelImage

___"syncWidget":___
        you can choose that the zoom in one image should do the same in the other images, or none

Parameter argv: arguments executablepath, image path1, imagepath 2.
return 0
###ZoomableImage
__Source:__ /manual\_test/zoomableimage

__Excutable:__ /build/debug/test\_manual\_zoomableimage

__ZoomableImage Test:__

- a window with 4 columns pops up
- the first column contains a spin box and two toggleable buttons
 ("autoshow", "fullimg")
- the 2nd column contains a vertical blue green image with a false color
palete at the top left
- the 3rd column contains a vertical blue image
- the 4th column contains an image of a red rook
- the images can be zoomed with the spin box ctrl+scroll or ctrl+shift+scroll
- if "autoshow" is toggled an the image is zoomed in (60 on the spin box)
 the pixel values are printed
- if "fullimg" is pressed the images are resized and the whole image is visible.
##Manual tests without executables:
###CallWindow
__Tests for the CallWindow:__

(The MainWindow is a CallWindow - it's not tested seperately.)

First off all: For all of the following tests, call the __test\_all (or the filters) test__ and click on the fast forward (">>") button.

1. Double click on at least 3 different items in the overview. They should open in a new tab in the main window. Double click on the same again, the call window should bring the currently open tabs to the front.
2. Use the context menu on at least 3 items in the overview to open them in a new window.
3. Open several tabs in different windows via the overview. This should work. Then move them around randomly in their windows and between different windows (use the context menu of the tabs for this test) and into new ones.
4. Open an item in a new window via the overview and close the tab of this item. The window surrounding the items tab should vanish.
5. Open several tabs in different windows via the overview. Then remove each of the tabs via the context menu of the tabs. They should vanish as well as their items in the overview.
6. Open several tabs in different windows via the overview. Close them via the close cross button and via the context menu.
7. Open several tabs in different windows via the overview. Click on an item that is already open. This should bring the appropriate tab and window to the front.
###Overview
__Tests for the Overview:__

(The OverviewPanel, OverviewTable, etc. are tested together)

First off all: For all of the following tests, call the __test\_all (or the filters) test__ and click on the fast forward (">>") button for all but the first two tests.

1. Click the "Step" button. A new item should appear in the list. Enter a filter query and hit <ENTER>, then hit "Step" button several times, the list should be updated according to your filter query each time.
2. Hit the fast forward button. The program should take some time and then present all items to you. The fast forward and the step button should be hidden now. Restart the test and hit the fast forward button after you typed a filter query and hit <ENTER>. The items should be sorted, filtered and grouped accordingly.
3. Hit the close button. The program should close without further GUI changes (it might take some time).
3. Try essentially every single filter sub query query possible (according to the [reference](http://cvv.mostlynerdless.de/ref/filterquery-ref.html)), the items should be filtered as written in the reference.
4. Try every possible single sort filter query (each time appending "asc", "desc" or ""), the items should be sorted as written in the reference.
5. Try the same with every grouping command
6. Combine some sub queries randomly to at least 5 queries consisting of a least 3 different sub queries. Type them each in, hit <ENTER>, the items should be filter, sorted and grouped correctly.
7. Use the context menu on at least 2 randomly chosen items to remove them and then try the 6. test.
8. Resize the main window and the use the slider at the bottom of the overview. The images in the table should be resized appropriately.
9. Use the other two context menu items on at least 3 randomly chosen items, they should do the right thing according to their titles.
10. Double click on at least 4 items. They should each be opened in a new tab in the main window.
11. Type random text into the filter query widget (while hitting enter), the application should not crash.
12. Try 11. while testing 6. to 10.. 
13. Hit the "Help" button. A web browser should open to the reference.
###RawView
__Tests for the Rawview:__
(The RawviewPanel, STFLEngine, RawviewTable, etc. are tested together)

First off all: Open the __match test__, click the step button and open the first item in the overview in a tab. Choose the RawView in the combobox at the top.

1. Try essentially every single filter sub query query possible (according to the [reference](http://cvv.mostlynerdless.de/ref/filterquery-ref.html)), the items should be filtered as written in the reference.
2. Try every possible single sort filter query (each time appending "asc", "desc" or ""), the items should be sorted as written in the reference.
3. Try the same with every grouping command
4. Combine some sub queries randomly to at least 5 queries consisting of a least 3 different sub queries. Type them each in, hit <ENTER>, the items should be filter, sorted and grouped correctly.
5. Select several different items, then use the context menu to copy them into your clipboard. Use every possible output mode and check the validity of the output in your clipboard.
6. Type random text into the filter query widget (while hitting enter), the application should not crash.
7. Hit the "Help" button. A web browser should open to the reference.
