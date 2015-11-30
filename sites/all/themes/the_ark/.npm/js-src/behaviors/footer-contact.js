(function ($) {
  Drupal.behaviors.theArkFooterContact = {
    attach: function () {
      var block = $('.footer-contact')
        , phoneNumbers = $('.footer-contact .phone');
      if (block.length === 0 || phoneNumbers.length === 0) return;

      phoneNumbers.each(function () { // ensure href for each phone link points to the correct phone number
        var number = $(this).text();
        if (!number) return;
        $(this).attr('href', 'tel:+' + number.replace(/\D/g,''));
      });
    }
  };
})(jQuery);
