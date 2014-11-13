# lutr

lutr (rhymes with clutter) is a utility for creating color lookup tables that map a color space down to a set of colors defined in a palette. In short, you throw a indexed color PNG in one end and lutr will spit a CUBE file out of the other.

I initially created lutr to support an index-style painting workflow in Photoshop. This is an extension of the [HD index painting in photoshop](http://danfessler.com/blog/hd-index-painting-in-photoshop) technique by [Dan Fessler](https://twitter.com/DanFessler) and is discussed a bit on my [TIGSource Art Improvement Thread](http://forums.tigsource.com/index.php?topic=26947.msg1054632#msg1054632).

## Install

Binaries can be downloaded from the [releases page](https://github.com/JSkelly/lutr/releases). This includes both the Windows and OSX versions of lutr. Windows users will need to have the [Visual C++ Redistributable Packages for Visual Studio 2013 ](http://www.microsoft.com/en-us/download/details.aspx?id=40784) installed.

## Use
Using lutr is easy:

    lutr mycoolimage.png

Will create a 3D lookup table named mycoolimage.png.cube.

## Support

Currently lutr supports several input formats and a single output format.

### Input
* PNG
* ACT
* PAL - Currently only JASC-PAL is supported.

### Output
* CUBE

## Contribute

You want to help make lutr better? High-five! Feel free to submit a pull request.

Did you make something mind-blowingly awesome using lutr? Right on! Do share the awesomeness with me.

## Credit

Joshua Skelton - [@JoshuaSkelly](https://twitter.com/JoshuaSkelly)

## License

This project is licensed under the [MIT license](https://github.com/JSkelly/lutr/blob/master/LICENSE).
