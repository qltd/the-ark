(function ($) {
  Drupal.behaviors.theArkRegionHeader = {
    attach: function () {
      var header = $('.l-regionwrapper--header');
      if (header.length === 0 || !Headroom) return;
      
      Headroom.options = Headroom.options || {};
      if ($('.front').length === 0) Headroom.options.offset = 170;
      else Headroom.options.offset = 340;
      header.headroom();
    }
  };
})(jQuery);
