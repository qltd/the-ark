(function ($) {
  Drupal.behaviors.theArkVideo = {
    attach: function () {
      var videos = $('.media-youtube-video, .media-vimeo-video');
      if (videos.length === 0) return;
      console.log(videos);
    }
  };
})(jQuery);
