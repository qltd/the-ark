(function ($) {
  var resizeMedia = function (videos) {
    var i = videos.length;
    while (i--) {
      var width = parseInt(videos[i].width || 0)
        , height = parseInt(videos[i].height || 0)
        , offsetWidth = parseInt(videos[i].offsetWidth || 0);
      if (height > 0 && width > 0 && offsetWidth > 0 && offsetWidth !== width)
        $(videos[i]).css('height', (( height * offsetWidth ) / width ) + 'px');
      else
        $(videos[i]).removeAttr('style');
    }
  };

  Drupal.behaviors.theArkVideo = {
    attach: function () {
      var videos = $('.media-youtube-player, .media-vimeo-player');
      if (videos.length === 0) return;

      $(window).on('resize', function () {
        resizeMedia(videos);
      });
      resizeMedia(videos);
    }
  };
})(jQuery);
